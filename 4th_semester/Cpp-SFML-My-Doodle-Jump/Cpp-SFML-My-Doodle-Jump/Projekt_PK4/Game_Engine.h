#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include "Score_Counter.h"
#include "MovingPlatform.h"
#include "Group_of_Plats.h"
#include "Jumper.h"
#include "Opponent.h"
#include "Window.h"
#include "Interface.h"
#include "Collision.h"
#include "Collision_with_Window_edges.h"
#include "Collision_with_Plat.h"
#include "Collision_with_Opponent.h"

class Collision_with_Window_edges;
class Game_Engine
{
	static bool is_beginning, is_end, permission_to_m_down,
		permission_t_m_right, permission_t_m_left;
public:
	Game_Engine() = default;
	~Game_Engine() = default;

	static bool get_is_beginning();
	static bool get_is_end();
	static bool get_permission_right();
	static bool get_permission_left();
	static void set_is_beginning(bool i_b);
	static void set_is_end(bool i_e);
	static void set_permission_to_m_down(bool per_t_m_p);
	static void set_permission_right(bool per_r);
	static void set_permission_left(bool per_l);

	void set_beginning_state(Score_Counter & counter, Group_of_Plats & group, Interface & iface, Jumper & jumper, Opponent & opponent, Window & window);
	void set_play(Score_Counter & counter, Group_of_Plats & group, Interface & iface, Jumper & jumper, Opponent & opponent, 
		Window & window, Collision_with_Window_edges & collision_window_e, Collision_with_Plat & collision_w_p, Collision_with_Opponent & collision_w_opp);
	
	void play();
	void game_loop(Score_Counter & counter, Group_of_Plats & group, Interface & iface, Jumper & jumper, Opponent & opponent, 
		Window & window, Collision_with_Window_edges & collision_window_e, Collision_with_Plat & collision_w_p, Collision_with_Opponent & collision_w_opp);
};
#endif // !GAME_ENGINE_H



