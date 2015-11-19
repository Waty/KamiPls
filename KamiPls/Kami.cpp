#include "Kami.h"
#include "CUserLocal.h"
#include "CMobPool.h"

uint32_t original_update = 0;

void __fastcall update(CUserLocal* ecx);

struct CUserLocalInternal
{
	struct IGObjVtbl { uint32_t* Update; }*vfptr;
};

void kami::enable(bool state)
{
	auto vfptr = reinterpret_cast<CUserLocalInternal*>(CUserLocal::GetInstance())->vfptr;
	if (state)
	{
		if (original_update == NULL) original_update = *vfptr->Update;
		vfptr->Update = reinterpret_cast<uint32_t*>(&update);

	}
	else if (original_update != NULL) vfptr->Update = &original_update;
}

void teleport(POINT pt)
{
	auto Teleport = reinterpret_cast<void(__thiscall*)(void* lpvEcx, bool bToggle, long x, long y)>(TeleportAddy);
	return Teleport(CUserLocal::GetInstance()->GetVecCtrl(), TRUE, pt.x, pt.y);
}

void __fastcall update(CUserLocal* ecx)
{
	auto closest_mob = CMobPool::GetInstance()->GetClosestMob(ecx->GetPos());
	if (closest_mob != nullptr) teleport(closest_mob->GetPos());

	reinterpret_cast<void(__thiscall *)(CUserLocal*)>(original_update);
}
