#pragma once
#include <Windows.h>
#include "ztl.h"

class IVecCtrlOwner
{
public:
	virtual int GetType() = 0;
	virtual int OnResolveMoveAction(int nInputX, int nInputY, int nCurMoveAction, void* pvc) = 0;
	virtual void OnLayerZChanged(void*) = 0;
	virtual ZRef<void>* GetShoeAttr(ZRef<void>* result) = 0;
	virtual POINT GetPos() = 0;
	virtual POINT GetPosPrev() = 0;
	virtual int GetZMass() = 0;
};

class CLife : public IGObj, public IVecCtrlOwner, public ZRefCounted
{
	~CLife() = delete;
};
