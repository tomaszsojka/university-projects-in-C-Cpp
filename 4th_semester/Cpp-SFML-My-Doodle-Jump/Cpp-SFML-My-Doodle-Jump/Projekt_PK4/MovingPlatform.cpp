#include "MovingPlatform.h"
#include "Draw.h"
#include <cmath>

float MovingPlatform::velocity_x = -1.5; // default


MovingPlatform::MovingPlatform(float x, float y) : Platform(x,y)
{
	default_coord_x = x;
}


MovingPlatform::~MovingPlatform()
{
}

void MovingPlatform::set_velocity_x(float vel_x)
{
	velocity_x = vel_x;
}

void MovingPlatform::Platform_move()
{
	Platform::Platform_move(); // w dol
	coord_x -= velocity_x; // w bok
	turn(); // zwrot
}

void MovingPlatform::Platform_move(bool permission_to_move)
{
	if (permission_to_move)
		Platform::Platform_move(); // w dol

	coord_x -= velocity_x; // w bok
	turn(); // zwrot
}

void MovingPlatform::turn()
{
	if (fabs(default_coord_x - coord_x) >= range_x)
	{
		velocity_x = -velocity_x;
		coord_x -= velocity_x; // raz sie przesuwam, zeby sie nie cofnal od razu
	}
}

void MovingPlatform::set_moving_plat( const Platform & to_replace)
{
	default_coord_x = to_replace.get_coord_x(); // podstawowy x, od ktorego bedzie sie poruszac
	coord_x = default_coord_x;
	coord_y = to_replace.get_coord_y();
}
