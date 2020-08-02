#ifndef INTERFACE_H
#define INTERFACE_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/String.hpp>
#include <string>

#include "Group_of_Plats.h"
class Interface
{
	sf::String window_title;
	unsigned int window_width, window_height;
	sf::RenderWindow app;
	sf::Texture t1, t2, t21, t22, t3, t4;
	sf::Sprite sBackground, sPlatform, sOneJumpPlatform, sJumper, sOpponent;
	sf::Font font;
	sf::Text score_text;
	sf::Text highscore_text;
public:
	Interface() = default;
	~Interface() = default;
	const sf::RenderWindow & get_app();
	void set_position_sPlatform(float x, float y);
	void set_position_sOneJumpPlatform(float x, float y);
	void set_position_sJumper(float x, float y);
	void set_position_sOpponent(float x, float y);
	void set_position_score_text(float x, float y);
	void set_size_score_text(unsigned int size);
	void set_string_score_text(std::string str);
	void set_string_hscore_text(std::string str);

	void draw_start_texts();
	void draw_end_texts();
	bool check_right_key();
	bool check_left_key();
	void draw(const sf::Sprite & s);
	void draw(const sf::Text & t);
	void draw_plats( const Group_of_Plats & g);
	void draw_all(const Group_of_Plats & g);
	void load_textures(std::string str1, std::string str2, std::string str3, std::string str4, std::string str5);
	void assign_sprites();
	void load_fonts(std::string str);
	void set_default_score_text();
	void create_window(unsigned int width, unsigned int height);
	void display_window();
	bool pollEvent( sf::Event & e);
	void app_close();
};
#endif // !INTERFACE_H


