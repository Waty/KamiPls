#pragma once
#include <stdint.h>

/**
* Contains updated adresses for MapleStory v116.1
* Updated using Waty's Automated AOB scanner
*/


const uint32_t CUserLocalPtr = 0x1A9E748; //TSingleton<CUserLocal>
const uint32_t CMobPoolPtr = 0x1AA2D14; //TSingleton<CMobPool> aka MobBasePtr
const uint32_t CDropPoolPtr = 0x1AA3554; //TSingleton<CDropPool>
const uint16_t CMobTemplateOffset = 0x254; //CMob::m_pTemplate
const uint16_t TemplateIdOffset = 0xB8; //CTemplate::m_templateId
