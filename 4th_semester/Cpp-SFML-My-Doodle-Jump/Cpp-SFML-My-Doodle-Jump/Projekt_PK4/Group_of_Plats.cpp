#include "Group_of_Plats.h"
#include "Draw.h"
#include <chrono>
#include <typeinfo>
#include <algorithm>
#include <iterator>
#include <thread>

Group_of_Plats::Group_of_Plats(unsigned int number)
{
	m_nr_to_replace = 0;
	c_nr_to_replace = number - 1; 
	number_of_plats = number;
	group0.reserve(number); // rezerwuje wczesniej miejsce, aby nie kopiowac za kazda dodana platforma
}

Group_of_Plats::~Group_of_Plats()
{
	for (int i = 0; i < group0.capacity(); i++)
	{
		if (typeid(*group0[i]) == typeid(MovingPlatform)) // zwracam wskaznik na ob klasy Platform, aby nie usunac MovingOne dwa razy
		{
			group0[i] = mov_base_point;
		}
		if (typeid(*group0[i]) == typeid(OneJumpPlatform)) // to samo z obiektem OneJumpPlatform
		{
			group0[i] = one_j_base_point;
		}
		delete group0[i];
	}
}

Platform * Group_of_Plats::get_member(unsigned int idx) const
{
	return group0.at(idx);
}

void Group_of_Plats::set_member(unsigned int idx, Platform * p_plat)
{
	group0[idx] = p_plat;
}

unsigned int Group_of_Plats::get_nr_of_plats() const
{
	return number_of_plats;
}

unsigned int Group_of_Plats::get_lower_idx() const
{
	int lower;
	if (upper_idx == number_of_plats - 1)
		lower = 0;
	else
		lower = upper_idx + 1;
	return lower;
}

void Group_of_Plats::set_upper_idx(unsigned int upper_i)
{
	upper_idx = upper_i;
}


void Group_of_Plats::make_group0(unsigned int window_width, unsigned int window_height)
{
	Draw drawer;

	float y_counter = 480, def_min_distance = 50, def_max_distance = 80;

	Platform * pnew_one = new Platform(200, 530);
	group0.emplace_back(pnew_one);
	std::vector<Platform *>::iterator it;
	//it = group0.begin();
	//it++;
	for (/*it = &group0.at(1); it != group0.end(); it++)//*/int i = 1; i < group0.capacity(); i++)
	{
		drawer.coordinates_draw(0.f, window_width - Platform::get_width(), def_min_distance, def_max_distance); // x,x, y,y
		std::this_thread::sleep_for(std::chrono::nanoseconds(1));	// inaczej kilka iteracji wykonywalo sie w jednej nanosekundzie 
																	// i wylosowane wspolrzedne platform byly takie same 
		Platform * pnew_one = new Platform(drawer.get_coord_x(), y_counter);
		group0.emplace_back(pnew_one);
		y_counter -= drawer.get_coord_y();
	}
	set_upper_idx(number_of_plats - 1); // ostatnia dodana platforma jest u gory
}

void Group_of_Plats::move_group(unsigned int window_height, bool permission)
{
	std::vector<Platform *>::iterator it;
	for (it = group0.begin(); it != group0.end(); it++)
	{
		int i = std::distance(group0.begin(), it);
		group0[i]->Platform_move(permission);
		if (group0[i]->get_coord_y() >= (float)(window_height + 2)) // platforma jest na dole
		{
			group0[i]->lower_to_upper(group0[upper_idx]->get_coord_y());
			set_upper_idx(i);
			if (typeid(**it) == typeid(MovingPlatform))
			{
				Draw drawer;
				do
				{
					drawer.integer_draw(0, number_of_plats - 1);
				} while (drawer.get_int_nr() == c_nr_to_replace);
				
				m_nr_to_replace = drawer.get_int_nr();
				mov_base_point->set_coord_x(group0[i]->get_coord_x());
				mov_base_point->set_coord_y(group0[i]->get_coord_y());
				group0[i] = mov_base_point; // rozlosuj pozycje
				mov_base_point = &moving_one;
			}

			if (m_nr_to_replace == i)
			{
				moving_one.set_moving_plat(*group0[i]);
				mov_base_point = group0[i];
				group0[i] = &moving_one;
			}
			if (typeid(**it) == typeid(OneJumpPlatform))
			{
				Draw drawer;
				do
				{
					drawer.integer_draw(0, number_of_plats - 1);
				} while (drawer.get_int_nr() == m_nr_to_replace); // jak chce zamienic za ten sam, co ruszajaca, to szuka innego
				c_nr_to_replace = drawer.get_int_nr();
				one_j_base_point->set_coord_x(group0[i]->get_coord_x());
				one_j_base_point->set_coord_y(group0[i]->get_coord_y());
				group0[i] = one_j_base_point; // rozlosuj pozycje
				one_j_base_point = &to_crush_one;
				one_j_base_point->set_is_visited(false);
			}
			if (c_nr_to_replace == i)
			{
				to_crush_one.set_coord_x(group0[i]->get_coord_x());
				to_crush_one.set_coord_y(group0[i]->get_coord_y());
				one_j_base_point = group0[i];
				group0[i] = &to_crush_one;
			}
		}
	}
}

void Group_of_Plats::change_group_position(unsigned int window_width, unsigned int window_height)
{
	Draw drawer;
	float y_counter = 480, def_min_distance = 50, def_max_distance = 80;
	group0[0]->set_coord_x(200);
	group0[0]->set_coord_y(530);
	for (int i = 1; i < group0.capacity(); i++)
	{
		drawer.coordinates_draw(0.f, window_width - Platform::get_width(), def_min_distance, def_max_distance); // x,x, y,y
		std::this_thread::sleep_for(std::chrono::nanoseconds(1));	// inaczej kilka iteracji wykonywalo sie w jednej nanosekundzie 
																	// i wylosowane wspolrzedne platform byly takie same
		group0[i]->set_coord_x(drawer.get_coord_x());
		group0[i]->set_coord_y(y_counter);
		y_counter -= drawer.get_coord_y();
	}
	set_upper_idx(number_of_plats - 1); // ostatnia dodana platforma jest u gory
}

