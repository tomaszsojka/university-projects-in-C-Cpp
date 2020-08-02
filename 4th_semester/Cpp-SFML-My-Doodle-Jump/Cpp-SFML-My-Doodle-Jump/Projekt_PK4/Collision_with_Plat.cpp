#include "Collision_with_Plat.h"
#include <typeinfo>

const Platform * Collision_with_Plat::get_p_plat()
{
	return p_plat_to_colide;
}

void Collision_with_Plat::set_p_plat(Platform * plat)
{
	p_plat_to_colide = plat;
}

void Collision_with_Plat::collision()
{
	float vel = -8;
	//jesli dol skoczka jest na platformie, i skoczek rusza sie w dol
	if ((p_jumper->get_coord_x() + Jumper::get_width() - 5 > p_plat_to_colide->get_coord_x()) && (p_jumper->get_coord_x() + 5 < p_plat_to_colide->get_coord_x() + Platform::get_width())
		&& (p_jumper->get_coord_y() + Jumper::get_height() - 10 > p_plat_to_colide->get_coord_y()) && (p_jumper->get_coord_y() + Jumper::get_height() - 10 < p_plat_to_colide->get_coord_y() + Platform::get_height() - 3)
		&& (MovingPlatform::get_velocity_y() > 0))
	{
		if (typeid(*p_plat_to_colide) != typeid(OneJumpPlatform))
		{
			MovingPlatform::set_velocity_y(vel);
		}
		else if (p_plat_to_colide->get_is_visited() == false)
		{
			MovingPlatform::set_velocity_y(vel);
			p_plat_to_colide->set_is_visited(true);
		}	
	}	
}
