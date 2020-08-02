#include "Collision_with_Window_edges.h"
#include "Game_Engine.h"
#include <string>

void Collision_with_Window_edges::set_p_window(Window * p_window)
{
	p_window_to_collide = p_window;
}

void Collision_with_Window_edges::set_p_interface(Interface * p_i)
{
	p_iface = p_i;
}

void Collision_with_Window_edges::set_p_s_counter(Score_Counter * p_s_c)
{
	p_s_counter = p_s_c;
}

void Collision_with_Window_edges::collision_w_bottom()
{
	if (p_jumper->get_coord_y() > p_window_to_collide->get_window_height() + Jumper::get_height())
	{
		Game_Engine::set_is_end(true);
	}
}

void Collision_with_Window_edges::collision_w_sensor_y()
{
	int round;
	if (p_jumper->get_coord_y() < p_window_to_collide->get_sensor_y())
	{
		Game_Engine::set_permission_to_m_down(true);
		p_s_counter->set_cur_score(p_s_counter->get_cur_score() + (p_window_to_collide->get_sensor_y() - p_jumper->get_coord_y()) / 10.f); // roznica, miedzy sensorem, a coord skoczka /10, bo za szybko rosl wynik wczesniej
		round = static_cast<int>(p_s_counter->get_cur_score());
		p_iface->set_string_score_text(std::to_string(round));
		p_jumper->set_coord_y((float)(p_window_to_collide->get_sensor_y()));
	}
	else
	{
		Game_Engine::set_permission_to_m_down(false);
	}
}

void Collision_with_Window_edges::collision_w_right_e()
{
	if (p_jumper->get_coord_x() + Jumper::get_width() >= p_window_to_collide->get_window_width())
	{
		Game_Engine::set_permission_right(false);
	}
	else
	{
		Game_Engine::set_permission_right(true);
	}
}

void Collision_with_Window_edges::collision_w_left_e()
{
	if (p_jumper->get_coord_x() <= 0.f)
	{
		Game_Engine::set_permission_left(false);
	}
	else
	{
		Game_Engine::set_permission_left(true);
	}

}

void Collision_with_Window_edges::collision_w_sides()
{
	collision_w_right_e();
	collision_w_left_e();
}

void Collision_with_Window_edges::collision()
{
	collision_w_bottom();
	collision_w_sensor_y();
	collision_w_sides();
}
