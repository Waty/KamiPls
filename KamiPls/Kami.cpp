#include "Kami.h"
#include "CUserLocal.h"
#include "CMobPool.h"
#include "CDropPool.h"
#include "CUserPool.h"

kami::mode mode;

namespace kami
{
	void* original_update = nullptr;

	void __fastcall update(CUserLocal* ecx);

	struct CUserLocalInternal
	{
		struct IGObjVtbl
		{
			void* Update;
		}*vfptr;
	};

	void enable(bool state)
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
		return Teleport(CUserLocal::GetInstance()->GetVecCtrl(), TRUE, pt.x, pt.y);
	}

	void set_x_offset(int value)
	{
		x = value;
	}

	void set_y_offset(int value)
	{
		y = value;
	}

	void set_mode(mode mode)
	{
		::mode = mode;
	}
}

namespace kami_loot
{
	int x, y;
	bool should_loot;

	void kami_loot::set_x_offset(int value)
	{
		x = value;
	}

	void kami_loot::set_y_offset(int value)
	{
		y = value;
	}
}

POINT get_tp_point(POINT user_loc)
{
	auto result = user_loc;

	if (mode == kami::mode::kiil_before_loot)
	{
		auto mob = CMobPool::GetInstance()->GetClosestMob(user_loc);
		if (mob != nullptr) result = mob->GetPos();
		else
		{
			auto drop = CDropPool::GetClosestDrop(user_loc);
			if (drop != nullptr)
			{
				result = drop->pt2;
				kami_loot::should_loot = true;
			}
		}
	}
	else if (mode == kami::mode::loot_before_kill)
	{
		auto drop = CDropPool::GetClosestDrop(user_loc);
		if (drop != nullptr)
		{
			result = drop->pt2;
			kami_loot::should_loot = true;
		}
		else
		{
			auto mob = CMobPool::GetInstance()->GetClosestMob(user_loc);
			if (mob != nullptr) result = mob->GetPos();
		}
	}
	else
	{
		auto calc_distance = [](POINT pt1, POINT pt2)
		{
			return pow(pt1.x - pt2.x, 2) + pow(pt1.y - pt2.y, 2);
		};
		double d1, d2, max;
		d1 = d2 = max = (std::numeric_limits<double>::max)();

		auto mob = CMobPool::GetInstance()->GetClosestMob(user_loc);
		if (mob) d1 = calc_distance(user_loc, mob->GetPos());

		auto drop = CDropPool::GetClosestDrop(user_loc);
		if (drop) d2 = calc_distance(user_loc, drop->pt2);

		if (d1 <= d2 && d1 != max) result = mob->GetPos();
		else if (d2 != max)
		{
			result = drop->pt2;
			kami_loot::should_loot = true;
		}
	}


	return result;
}

POINT apply_offset(POINT pt, bool is_loot)
{
	if (is_loot) return{ pt.x + kami_loot::x, pt.y + kami_loot::y };
	return{ pt.x + kami::x , pt.y + kami::y };
}

bool allowed_to_kami()
{
	return CUserPool::size() <= 1;
}

void __fastcall kami::update(CUserLocal* ecx)
{
	if (allowed_to_kami())
	{
		auto user_loc = CUserLocal::GetInstance()->GetPos();
		auto new_pos = apply_offset(get_tp_point(user_loc), kami_loot::should_loot);

		teleport(new_pos);

		if (kami_loot::should_loot) CDropPool::TryPickUpDrop(new_pos);
		kami_loot::should_loot = false;
	}
	reinterpret_cast<void(__thiscall *)(CUserLocal*)>(original_update)(ecx);
}

