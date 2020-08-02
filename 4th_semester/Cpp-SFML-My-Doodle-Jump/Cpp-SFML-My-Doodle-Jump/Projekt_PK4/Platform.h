#ifndef PLATFORM_H
#define PLATFORM_H
#include "Drawable_Obj.h"
class Platform : public Drawable_Obj<Platform>
{
protected: 
	//float coord_x, coord_y;
	
	static float velocity_y;// , width, height; // nie wiem czy jest potrzebne, to sie zobaczy
public:
	Platform();
	Platform(float x, float y);
	~Platform() = default;

	//float get_coord_x() const;
	//float get_coord_y() const;
	static float get_velocity_y();
	//static float get_width();
	//static float get_height();
	//void set_coord_x(float x);
	//void set_coord_y(float y);
	static void set_velocity_y(float vel_y);
	virtual void Platform_move();
	virtual void Platform_move(bool permission_to_move);
	virtual bool get_is_visited() const;
	virtual void set_is_visited(bool is_v);
	void lower_to_upper(float prior_upper); // dolna platforma na gore
};
#endif // !PLATFORM_H
