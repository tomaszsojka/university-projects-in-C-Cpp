#ifndef GROUP_OF_PLATS_H
#define GROUP_OF_PLATS_H
#include "MovingPlatform.h"
#include "OneJumpPlatform.h"
#include <vector>

class Group_of_Plats
{
	std::vector <Platform*> group0;
	Platform * mov_base_point = &moving_one;
	Platform * one_j_base_point = &to_crush_one;
	MovingPlatform moving_one;

	OneJumpPlatform to_crush_one;
	unsigned int number_of_plats, upper_idx, m_nr_to_replace, c_nr_to_replace; 
public:
	Group_of_Plats() = delete;
	Group_of_Plats(unsigned int number);
	~Group_of_Plats();

	Platform * get_member(unsigned int idx) const; 
	void set_member(unsigned int idx, Platform * p_plat);
	unsigned int get_nr_of_plats() const;
	unsigned int get_lower_idx() const;
	void set_upper_idx(unsigned int upper_i);
	void make_group0(unsigned int window_width, unsigned int window_height);
	void move_group(unsigned int window_height, bool permission);
	void change_group_position(unsigned int window_width, unsigned int window_height);
};
#endif // !GROUP_OF_PLATS_H


