#include "Game_Engine.h"
#include <iostream>
#include <string>
#include <chrono>
#include <thread>


#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/String.hpp>
#include "OneJumpPlatform.h"
#include "Draw.h"

#include "Interface.h"

bool Game_Engine::is_beginning = true, Game_Engine::is_end = false, Game_Engine::permission_to_m_down = false, Game_Engine::permission_t_m_right = true,
Game_Engine::permission_t_m_left = true;


bool Game_Engine::get_is_beginning()
{
	return is_beginning;
}

bool Game_Engine::get_is_end()
{
	return is_end;
}

bool Game_Engine::get_permission_right()
{
	return permission_t_m_right;
}

bool Game_Engine::get_permission_left()
{
	return permission_t_m_left;
}


void Game_Engine::set_is_beginning(bool i_b)
{
	is_beginning = i_b;
}

void Game_Engine::set_is_end(bool i_e)
{
	is_end = i_e;
}

void Game_Engine::set_permission_to_m_down(bool per_t_m_p)
{
	permission_to_m_down = per_t_m_p;
}

void Game_Engine::set_permission_right(bool per_r)
{
	permission_t_m_right = per_r;
}

void Game_Engine::set_permission_left(bool per_l)
{
	permission_t_m_left = per_l;
}


void Game_Engine::set_beginning_state(Score_Counter & counter, Group_of_Plats & group, Interface & iface, Jumper & jumper, Opponent & opponent, Window & window)
{
	float velocity_x = -1.5, somwhere_out_of_window = -70, over = 2;
	try
	{
		counter.load_highscore("data/highscore.txt");
	}
	catch (std::string ex)
	{
		std::cout << ex;
	}
	MovingPlatform::set_velocity_y(0.0);
	MovingPlatform::set_velocity_x(velocity_x);
	Opponent::set_velocity_y(0.0);
	Opponent::set_velocity_x(velocity_x * 2);
	group.change_group_position(window.get_window_width(), window.get_window_height());
	opponent.set_random_position(window.get_window_width());
	counter.set_cur_score(0.f);
	iface.set_default_score_text();
	iface.set_string_hscore_text(std::to_string(counter.get_highscore()));
	iface.set_position_sOneJumpPlatform(somwhere_out_of_window, somwhere_out_of_window);
	jumper.set_coord_x(group.get_member(group.get_lower_idx())->get_coord_x() + over);
	jumper.set_coord_y(group.get_member(group.get_lower_idx())->get_coord_y() - Jumper::get_height());
}

void Game_Engine::set_play(Score_Counter & counter, Group_of_Plats & group, Interface & iface, Jumper & jumper, Opponent & opponent, Window & window, Collision_with_Window_edges & collision_window_e, Collision_with_Plat & collision_w_p, Collision_with_Opponent & collision_w_opp)
{

	iface.create_window(window.get_window_width(), window.get_window_height());
	try
	{
		iface.load_textures("images/my_back.png", "images/my_plat.png", "images/crushed_plat.png", "images/jumper.png", "images/farfetchd_s.png");
	}
	catch (std::string ex)
	{
		std::cout << ex;
	}
	iface.assign_sprites();
	try
	{
		iface.load_fonts("fonts/ARCADECLASSIC.ttf");
	}
	catch (std::string ex)
	{
		std::cout << ex;
	}
	group.make_group0(window.get_window_width(), window.get_window_height());
	set_beginning_state(counter, group, iface, jumper, opponent, window);
	collision_w_p.set_p_jumper(&jumper);
	

	collision_window_e.set_p_jumper(&jumper);
	collision_window_e.set_p_interface(&iface);
	collision_window_e.set_p_s_counter(&counter);
	collision_window_e.set_p_window(&window);

	collision_w_opp.set_p_jumper(&jumper);
	collision_w_opp.set_p_opp(&opponent);
}

void Game_Engine::play()
{
	unsigned int nr_of_plats = 11, window_height = 533, window_width = 400, sensor_y = 200;
	Interface iface;
	Window window(window_width,window_height,sensor_y);
	Score_Counter counter;
	Group_of_Plats group(nr_of_plats);
	Jumper jumper;
	Opponent opponent;
	Collision_with_Plat collision_w_p;
	Collision_with_Window_edges collision_window_e;
	Collision_with_Opponent collision_w_opp;

	set_play(counter, group, iface, jumper, opponent, window, collision_window_e, collision_w_p, collision_w_opp);
	
	game_loop(counter, group, iface, jumper, opponent, window, collision_window_e, collision_w_p, collision_w_opp);
}

void Game_Engine::game_loop(Score_Counter & counter, Group_of_Plats & group, Interface & iface, Jumper & jumper, Opponent & opponent, Window & window, Collision_with_Window_edges & collision_window_e, Collision_with_Plat & collision_w_p, Collision_with_Opponent & collision_w_opp)
{
	float velocity_jumper = 3, dy = (float)0.2;

	while (iface.get_app().isOpen())
	{
		
		sf::Event e;
		while (iface.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
			{
				counter.save_highscore("data/highscore.txt");
				iface.app_close();
			}
		}
		if (e.type = sf::Event::KeyPressed)
		{
			if (get_is_beginning())
			{
				if (e.key.code == sf::Keyboard::Space)
				{
					iface.set_string_hscore_text(std::to_string(counter.get_highscore()));
					set_is_beginning(false);
				}
			}
			if (get_is_end())
			{
				if (e.key.code == sf::Keyboard::Enter)
				{
					set_is_beginning(true);
					set_is_end(false);
					counter.save_highscore("data/highscore.txt");
					set_beginning_state(counter, group, iface, jumper, opponent,window);
				}
				if (e.key.code == sf::Keyboard::Escape)
				{
					iface.app_close();
				}
			}

		}

		collision_window_e.collision();
		if (!Game_Engine::get_is_end())
		{
			if (iface.check_right_key() && Game_Engine::get_permission_right())
				jumper.set_coord_x(jumper.get_coord_x() + velocity_jumper);
			if (iface.check_left_key() && Game_Engine::get_permission_left())
				jumper.set_coord_x(jumper.get_coord_x() - velocity_jumper);
		}
		if (!Game_Engine::get_is_beginning()) // nie na poczatku
		{
			MovingPlatform::set_velocity_y(MovingPlatform::get_velocity_y() + dy);
			jumper.set_coord_y(jumper.get_coord_y() + MovingPlatform::get_velocity_y());

			
			collision_w_opp.collision();

			group.move_group(window.get_window_height(), permission_to_m_down);
			Opponent::set_velocity_y(MovingPlatform::get_velocity_y()); // zgrywam predkosc spadania w dol z platformami
			opponent.Opponent_move(window.get_window_width(),window.get_window_height(), permission_to_m_down);

			if (!Game_Engine::get_is_end())
			{
				for (unsigned int i = 0; i < group.get_nr_of_plats(); i++)
				{
					collision_w_p.set_p_plat(group.get_member(i));
					collision_w_p.collision();
				}
			}
		}
		iface.set_position_sJumper(jumper.get_coord_x(), jumper.get_coord_y());
		iface.set_position_sOpponent(opponent.get_coord_x(), opponent.get_coord_y());
		iface.draw_all(group);
		
		if (Game_Engine::get_is_beginning())
		{
			iface.draw_start_texts();
		}
		if (Game_Engine::get_is_end())
		{
			iface.draw_end_texts();
		}
		iface.display_window();
	}
}



