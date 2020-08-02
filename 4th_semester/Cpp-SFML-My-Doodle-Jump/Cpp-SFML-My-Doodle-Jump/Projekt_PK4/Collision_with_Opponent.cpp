#include "Collision_with_Opponent.h"
#include "Game_Engine.h"

const Opponent * Collision_with_Opponent::get_p_opp()
{
	return p_opp_to_collide;
}

void Collision_with_Opponent::set_p_opp(Opponent * opp)
{
	p_opp_to_collide = opp;
}

void Collision_with_Opponent::collision()
{
	if ((p_jumper->get_coord_x() + Jumper::get_width() - 10 > p_opp_to_collide->get_coord_x()) && (p_jumper->get_coord_x() + 10 < p_opp_to_collide->get_coord_x() + Opponent::get_width())
		&& (p_jumper->get_coord_y() + Jumper::get_height() > p_opp_to_collide->get_coord_y() + 20) && (p_jumper->get_coord_y() + 10 < p_opp_to_collide->get_coord_y() + Opponent::get_height()))
	{
		Game_Engine::set_is_end(true);
	}
}
