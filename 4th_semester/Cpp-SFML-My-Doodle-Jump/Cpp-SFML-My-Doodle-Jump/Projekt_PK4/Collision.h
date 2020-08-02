#ifndef COLLISION_H
#define COLLISION_H
#include "Jumper.h"
class Collision
{
protected:
	Jumper * p_jumper;
public:
	const Jumper * get_p_jumper();
	void set_p_jumper(Jumper * p_jum);
	virtual void collision() = 0;
};
#endif // !COLLISION_H



