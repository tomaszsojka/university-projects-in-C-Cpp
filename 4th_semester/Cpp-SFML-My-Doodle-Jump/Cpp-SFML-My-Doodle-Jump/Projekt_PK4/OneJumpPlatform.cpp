#include "OneJumpPlatform.h"



OneJumpPlatform::OneJumpPlatform(float x, float y) : Platform(x,y)
{
}


OneJumpPlatform::~OneJumpPlatform()
{
}

bool OneJumpPlatform::get_is_visited() const
{
	return is_visited;
}


void OneJumpPlatform::set_is_visited(bool is_v)
{
	is_visited = is_v;
}
