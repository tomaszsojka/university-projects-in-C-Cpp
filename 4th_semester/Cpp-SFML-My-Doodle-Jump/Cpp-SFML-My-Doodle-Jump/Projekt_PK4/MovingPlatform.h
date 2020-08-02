#ifndef MOVINGPLATFORM_H
#define MOVINGPLATFORM_H

#include "Platform.h"
class MovingPlatform : public Platform
{
	float range_x = 90.f; //default range to left and right, so it's *2
	float default_coord_x; // from there it starts moving
	static float velocity_x;
public:
	MovingPlatform() = default;
	MovingPlatform(float x, float y);
	~MovingPlatform();

	static void set_velocity_x(float vel_x);
	void Platform_move() override;
	void Platform_move(bool permission_to_move) override;
	void turn();
	void set_moving_plat(const Platform & to_replace);
};
#endif // !MOVINGPLATFORM_H
