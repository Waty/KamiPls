#pragma once
#include <stdint.h>

/**
* Contains updated adresses for MapleStory v114.1
* Updated using Waty's Automated AOB scanner
*/


const uint32_t CMobPoolPtr = 0x199B290; //TSingleton<CMobPool> aka MobBasePtr
const uint32_t CDropPoolPtr = 0x199B8D4; //TSingleton<CDropPool>
const uint16_t CMobTemplateOffset = 0x240; //CMob::m_pTemplate
const uint16_t TemplateIdOffset = 0xB8; //CTemplate::m_templateId
