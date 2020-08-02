#include "Collision.h"

const Jumper * Collision::get_p_jumper()
{
	return p_jumper;
}

void Collision::set_p_jumper(Jumper * p_jum)
{
	p_jumper = p_jum;
}
