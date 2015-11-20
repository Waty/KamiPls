#pragma once

namespace kami
{
	enum class mode
	{
		kiil_before_loot,
		loot_before_kill,
		shortest_distance
	};

	void enable(bool state);
	void set_x_offset(int value);
	void set_y_offset(int value);
	void set_mode(mode mode);
}

namespace kami_loot
{
	void set_x_offset(int value);
	void set_y_offset(int value);
}