#ifndef COLLISION_WITH_OPPONENT_H
#define COLLISION_WITH_OPPONENT_H
#include "Collision.h"
#include "Opponent.h"
class Collision_with_Opponent : public Collision
{
	Opponent * p_opp_to_collide;
public:
	Collision_with_Opponent() = default;
	~Collision_with_Opponent() = default;

	const Opponent * get_p_opp();
	void set_p_opp(Opponent * opp);
	void collision() override;
};
#endif // !COLLISION_WITH_OPPONENT_H



