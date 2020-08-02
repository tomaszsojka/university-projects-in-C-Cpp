#include "Platform.h"
#include "Draw.h"

float Platform::velocity_y = 0;// , Platform::width = 67, Platform::height = 17; // default

Platform::Platform()
{
	width = 67;
	height = 17;
}

Platform::Platform(float x, float y) : Platform()
{
	coord_x = x;
	coord_y = y;
}
/*
float Platform::get_coord_x() const
{
	return coord_x;
}

float Platform::get_coord_y() const
{
	return coord_y;
}
*/
float Platform::get_velocity_y()
{
	return velocity_y;
}
/*
float Platform::get_width()
{
	return width;
}

float Platform::get_height()
{
	return height;
}


void Platform::set_coord_x(float x)
{
	coord_x = x;
}

void Platform::set_coord_y(float y)
{
	coord_y = y;
}
*/
void Platform::set_velocity_y(float vel_y)
{
	velocity_y = vel_y;
}

void Platform::Platform_move()
{
	coord_y -= velocity_y;
}

void Platform::Platform_move(bool permission_to_move)
{
	if (permission_to_move)
	{
		coord_y -= velocity_y;
	}
}

bool Platform::get_is_visited() const
{
	return false;
}

void Platform::set_is_visited(bool is_v)
{
}

void Platform::lower_to_upper(float prior_upper)
{
	Draw drawer;
	float def_min_distance = 50, def_max_distance = 80;
	drawer.coordinates_draw(0.f, 400 - Platform::get_width(), def_min_distance, def_max_distance); // po jakims czasie zwiekszyc y-ki
	set_coord_x(drawer.get_coord_x());
	set_coord_y(prior_upper - drawer.get_coord_y());
}
