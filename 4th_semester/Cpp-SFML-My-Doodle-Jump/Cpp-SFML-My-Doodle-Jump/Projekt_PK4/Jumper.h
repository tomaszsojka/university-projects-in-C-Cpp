#ifndef JUMPER_H
#define JUMPER_H
#include "Drawable_Obj.h"
class Jumper : public Drawable_Obj<Jumper>
{
	//float coord_x, coord_y;
	//static float width, height;
public:
	Jumper();
	~Jumper();
	//float get_coord_x() const;
	//float get_coord_y() const;
	//static float get_width();
	//static float get_height();

	//void set_coord_x(float x);
	//void set_coord_y(float y);
};
#endif // !JUMPER_H



