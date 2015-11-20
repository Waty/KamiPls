#pragma once
#include "TSingleton.h"
#include "ZList.h"
#include "ZMap.h"
#include "ztl.h"
#include "Addys.h"
#include <Windows.h>
#include "TSecType.h"
#include <algorithm>

#pragma pack(push, 1)
struct DROP
{
	char gap_0[12];
	SECPOINT pt1;
	void* a;
	void* posList;
	char nEnterType;
	char bReal;
	char gap_2E[2];
	unsigned int dwId;
	unsigned int dwOwnerID;
	unsigned int dwSourceID;
	int nOwnType;
	int bIsMoney;
	int nInfo;
	void* pLayer;
	void* pvec;
	int tCreateTime;
	int tLeaveTime;
	int nState;
	int tTickTime;
	int tEndParabolicMotion;
	int tLastTryPickUp;
	int dwPickUpId;
	char gap_6C[4];
	long double fAngle;
	SECPOINT pt2;
	_FILETIME m_dateExpire;
	int bByPet;
};
#pragma pack(pop)


struct CDropPool : TSingleton<CDropPool, CDropPoolPtr>
{
	virtual ~CDropPool() = 0;

	static int size()
	{
		if (!IsInitialized()) return 0;
		return GetInstance()->m_lDrop.count();
	}

	int m_tLastExplodeSound;
	ZMap<unsigned long, ZRef<DROP>, unsigned long> m_mDrop;
	ZList<ZRef<DROP>> m_lDrop;
	ZMap<unsigned long, POINT, unsigned long> m_mDropPt;
	void* m_pPropMoneyIcon;
	void* m_pAttrField;
	ZList<POINT> m_lpRecentPickupedItem;
	int m_bRecentPickupedItemCheck;

	static void TryPickUpDrop(POINT& ppt)
	{
		auto TryPickUpDrop = reinterpret_cast<void(__thiscall*)(CDropPool* lpvEcx, POINT& pt)>(TryPickUpDropAddy);
		if (IsInitialized())
		{
			TryPickUpDrop(GetInstance(), ppt);
		}
	}

	static DROP* GetClosestDrop(POINT target)
	{
		auto calc_distance = [](POINT pt1, POINT pt2) {return pow(pt1.x - pt2.x, 2) + pow(pt1.y - pt2.y, 2); };

		DROP* result = nullptr;
		auto shortest_distance = (std::numeric_limits<double>::max)();
		for (auto& drop : GetInstance()->m_lDrop) {

			if (drop->nInfo == 0) continue;

			auto distance = calc_distance(drop->pt2, target);
			if (distance < shortest_distance) {
				shortest_distance = distance;
				result = drop;
			}
		}
		return result;
	}
};
