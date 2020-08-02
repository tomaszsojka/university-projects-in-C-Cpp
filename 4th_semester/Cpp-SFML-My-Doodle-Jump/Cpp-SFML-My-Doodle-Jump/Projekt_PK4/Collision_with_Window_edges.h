#ifndef COLLISION_WITH_WINDOW_EDGES_H
#define COLLISION_WITH_WINDOW_EDGES_H

#include "Collision.h"
#include "Window.h"
#include "Interface.h"
#include "Score_Counter.h"
class Collision_with_Window_edges : public Collision
{
	Window * p_window_to_collide;
	Interface * p_iface;
	Score_Counter * p_s_counter;
public:
	Collision_with_Window_edges() = default;
	~Collision_with_Window_edges() = default;

	void set_p_window(Window * p_window);
	void set_p_interface(Interface * p_i);
	void set_p_s_counter(Score_Counter * p_s_c);
	void collision_w_bottom();
	void collision_w_sensor_y();
	void collision_w_right_e();
	void collision_w_left_e();
	void collision_w_sides();
	void collision() override;
};
#endif // !COLLISION_WITH_WINDOW_EDGES_H


