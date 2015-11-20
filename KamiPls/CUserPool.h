#pragma once
#include "TSingleton.h"
#include "CUserLocal.h"
#include "ZMap.h"

class CUserPool : public TSingleton<CUserPool, CUserPoolPtr>, public IGObj
{
public:
	struct USERREMOTE_ENTRY { };

	ZRef<CUserLocal> m_pUserLocal;
	ZMap<unsigned long, ZRef<USERREMOTE_ENTRY>, unsigned long> m_mUserRemote;
	ZList<ZRef<USERREMOTE_ENTRY>> m_lUserRemote;


	static uint32_t size()
	{
		if (!IsInitialized()) return 0;
		return GetInstance()->m_mUserRemote.count();
	}
};
