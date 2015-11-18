#pragma once
#include "Addys.h"
#include "TSingleton.h"
#include "CLife.h"

class CAvatar
{
public:
	virtual ~CAvatar() = delete;
	virtual int CanUseBareHand() = 0;
	virtual int IsEvanJob() = 0;
	virtual void OnAvatarModified() = 0;
	virtual void SetMoveAction(int, int) = 0;
	virtual void PrepareActionLayer(int, int, int) = 0;
};

class CUser : public CLife, public CAvatar { ~CUser() = delete; };

class CUserLocal : public CUser, public TSingleton<CUserLocal, CUserLocalPtr>
{
	~CUserLocal() = delete;
public:
	//shit for skillinjection, not needed atm
	//int TryDoingMeleeAttack(SKILLENTRY* entry, uint32_t skilllevel);
	//int TryDoingShootAttack(SKILLENTRY* pSkill, int nSLV, int nShootRange0 = 65, int bMortalBlow = 0, int tKeyDown = 0, unsigned int nRandForMortalBlowAction = 0, void* unknown = nullptr);
};
