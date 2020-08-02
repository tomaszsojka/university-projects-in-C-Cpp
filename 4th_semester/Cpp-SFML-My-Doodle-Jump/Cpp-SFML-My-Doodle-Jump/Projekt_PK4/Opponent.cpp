#include "Opponent.h"
#include "Draw.h"

float Opponent::velocity_x = -1.5, Opponent::velocity_y = 0;// , Opponent::width = 74, Opponent::height = 67;

Opponent::Opponent()
{
	width = 74;
	height = 67;
}

Opponent::Opponent(float x, float y) : Opponent()
{
	coord_x = x;
	coord_y = y;
}
/*
float Opponent::get_coord_x() const
{
	return coord_x;
}

float Opponent::get_coord_y() const
{
	return coord_y;
}

float Opponent::get_width()
{
	return width;
}

float Opponent::get_height()
{
	return height;
}
*/
float Opponent::get_velocity_y()
{
	return velocity_y;
}
/*
void Opponent::set_coord_x(float x)
{
	coord_x = x;
}

void Opponent::set_coord_y(float y)
{
	coord_y = y;
}
*/
void Opponent::set_velocity_x(float vel_x)
{
	velocity_x = vel_x;
}

void Opponent::set_velocity_y(float vel_y)
{
	velocity_y = vel_y;
}

void Opponent::Opponent_move(unsigned int window_width, unsigned int window_height, bool permission_to_move)
{

	coord_x -= velocity_x;
	if (permission_to_move)
	{
		coord_y -= velocity_y;
	}

	if (coord_y >= (float)(window_height + 2))
	{
		set_random_position(window_width);
	}

	if (coord_x >= (float)(window_width + 2))
	{
		right_to_left();
	}
}

void Opponent::set_random_position(unsigned int window_width)
{
	Draw drawer;
	////////
	float def_max_distance = -Opponent::get_width() - 2, def_min_distance = -250;
	drawer.coordinates_draw(0.f, window_width - Opponent::get_width(), def_min_distance, def_max_distance);
	set_coord_x(drawer.get_coord_x());
	set_coord_y(drawer.get_coord_y());
}

void Opponent::right_to_left()
{
	set_coord_x(-Opponent::get_width());
}
