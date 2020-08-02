#ifndef OPPONENT_H
#define OPPONENT_H
#include "Drawable_Obj.h"
class Opponent : public Drawable_Obj<Opponent>
{
	//float coord_x, coord_y;
	static float velocity_x, velocity_y;// , width, height;
public:
	Opponent();
	Opponent(float x, float y);
	~Opponent() = default;

	//float get_coord_x() const;
	//float get_coord_y() const;
	//static float get_width();
	//static float get_height();
	static float get_velocity_y();

	//void set_coord_x(float x);
	//void set_coord_y(float y);
	static void set_velocity_x(float vel_x);
	static void set_velocity_y(float vel_y);
	void Opponent_move(unsigned int window_width, unsigned int window_height, bool permission_to_move);
	void set_random_position(unsigned int window_width);
	void right_to_left();
};
#endif // !OPPONENT_H



