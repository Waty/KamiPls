#pragma once
#include "CMob.h"
#include "ZList.h"
#include "TSingleton.h"
#include "ZMap.h"
#include <limits>

class CMobPool : public TSingleton<CMobPool, CMobPoolPtr>
{
	virtual ~CMobPool() = 0;

	static double calcDistance(const POINT pt1, const POINT pt2)
	{
		int a = pt1.x - pt2.x;
		int b = pt1.y - pt2.y;
		return a * a + b * b;
	};

public:
	ZMap<unsigned long, __POSITION *, unsigned long> m_mMob;
	ZList<ZRef<CMob>> mobs_;
	ZList<ZRef<CMob>> mob_delayed_dead_;
	ZList<ZRef<CMob>> mob_dead_process_;
	ZRef<CMob> mob_damaged_by_mob_;
	int last_hit_mob_damaged_by_mob_;
	ZRef<CMob> guided_mob_;
	unsigned int mob_crc_key_;

	size_t valid_mobs()
	{
		size_t i = 0;
		for_each([&i](CMob* mob) {
			++i;
		});
		return i;
	}

	template <typename Func>
	void for_each(Func func)
	{
		for (auto& mob : mobs_) {
			if (mob->template_->templateId == 9999999) continue;

			func(mob);
		}
	}

	CMob* GetClosestMob(const POINT user)
	{
		CMob* result = nullptr;
		double distance = (std::numeric_limits<double>::max)();

		for_each([&](CMob* mob) {
			auto dist = calcDistance(user, mob->GetPos());
			if (dist < distance) {
				distance = dist;
				result = mob;
			}
		});

		return result;
	}
};

static_assert(sizeof(CMobPool) == 0x70, "CMobPool compiled to a wrong size");
