#pragma once
#include "CLife.h"
#include "ZtlSecure.h"
#include "Addys.h"

class CMobTemplate
{
	char padding[TemplateIdOffset];
public:
	ZtlSecure<uint32_t> templateId;
};
static_assert(offsetof(CMobTemplate, templateId) == TemplateIdOffset, "CMobTemplate thas a invalid offset!");

class CMob : public CLife
{
	~CMob() = delete;
	char padding_[CMobTemplateOffset - sizeof(CLife)];
public:
	CMobTemplate* template_;
};

static_assert(offsetof(CMob, template_) == CMobTemplateOffset, "CMob thas a invalid offset!");
