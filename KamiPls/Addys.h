#pragma once
#include <stdint.h>

/**
* Contains updated adresses for MapleStory v116.2
* Updated using Waty's Automated AOB scanner
*/


const uint32_t CUserLocalPtr = 0x01BFC3A0; //TSingleton<CUserLocal>
const uint32_t CMobPoolPtr = 0x01C00984; //TSingleton<CMobPool> aka MobBasePtr
const uint32_t CDropPoolPtr = 0x01C011DC; //TSingleton<CDropPool>
const uint16_t CMobTemplateOffset = 0x254; //CMob::m_pTemplate
const uint16_t TemplateIdOffset = 0xB8; //CTemplate::m_templateId
const uint32_t TeleportAddy = 0x1290CB0;
const uint32_t TryPickUpDropAddy = 0x006B8BC0;
