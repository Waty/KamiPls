#include "Kami.h"
#include "CUserLocal.h"
#include "CMobPool.h"

void* original_update = nullptr;

void __fastcall update(CUserLocal* ecx);

struct CUserLocalInternal
{
	struct IGObjVtbl { void* Update; }*vfptr;
};

void kami::enable(bool state)
{
	auto vfptr = reinterpret_cast<CUserLocalInternal*>(CUserLocal::GetInstance())->vfptr;
	if (state)
	{
		if (original_update == nullptr) original_update = vfptr->Update;
		vfptr->Update = &update;

	}
	else if (original_update != nullptr) vfptr->Update = original_update;
}

int x, y;
void teleport(POINT pt)
{
	auto Teleport = reinterpret_cast<void(__thiscall*)(void* vecCtrl, bool bToggle, long x, long y)>(TeleportAddy);
	return Teleport(CUserLocal::GetInstance()->GetVecCtrl(), TRUE, pt.x + x, pt.y + y);
}

void __fastcall update(CUserLocal* ecx)
{
	auto closest_mob = CMobPool::GetInstance()->GetClosestMob(ecx->GetPos());
	if (closest_mob != nullptr) teleport(closest_mob->GetPos());

	reinterpret_cast<void(__thiscall *)(CUserLocal*)>(*reinterpret_cast<void**>(original_update));
}

void kami::set_x_offset(int value) { x = value; }
void kami::set_y_offset(int value) { y = value; }
