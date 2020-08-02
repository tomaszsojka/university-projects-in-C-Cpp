#ifndef COLLISION_WITH_PLAT_H
#define COLLISION_WITH_PLAT_H

#include "Collision.h"
#include "Platform.h"
#include "MovingPlatform.h"
#include "OneJumpPlatform.h"
class Collision_with_Plat : public Collision
{
	Platform * p_plat_to_colide;
public:
	Collision_with_Plat() = default;
	~Collision_with_Plat() = default;
	const Platform * get_p_plat();
	void set_p_plat(Platform * plat);
	void collision() override;
};


#endif // !COLLISION_WITH_PLAT_H

