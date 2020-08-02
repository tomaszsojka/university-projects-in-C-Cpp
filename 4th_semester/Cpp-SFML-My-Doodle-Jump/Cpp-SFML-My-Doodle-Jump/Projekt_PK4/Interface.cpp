#include "Interface.h"
#include <typeinfo>
#include "Platform.h"
#include "OneJumpPlatform.h"
#include "MovingPlatform.h"

const sf::RenderWindow & Interface::get_app()
{
	return app;
}

void Interface::set_position_sPlatform(float x, float y)
{
	sPlatform.setPosition(x, y);
}

void Interface::set_position_sOneJumpPlatform(float x, float y)
{
	sOneJumpPlatform.setPosition(x,y);
}

void Interface::set_position_sJumper(float x, float y)
{
	sJumper.setPosition(x, y);
}

void Interface::set_position_sOpponent(float x, float y)
{
	sOpponent.setPosition(x, y);
}

void Interface::set_position_score_text(float x, float y)
{
	score_text.setPosition(x, y);
}

void Interface::set_size_score_text(unsigned int size)
{
	score_text.setCharacterSize(size);
}

void Interface::set_string_score_text(std::string str)
{
	score_text.setString(str);
}

void Interface::set_string_hscore_text(std::string str)
{
	highscore_text.setString(str);
}

void Interface::draw_start_texts()
{
	sf::Text title;
	title.setFont(font);
	title.setString("Jynx Jump");
	title.setFillColor(sf::Color::Black);
	title.setCharacterSize(70);
	title.setPosition((float)((window_width - title.getLocalBounds().width) / 2), (float)(window_height / 4));
	
	
	highscore_text.setFont(font);
	highscore_text.setFillColor(sf::Color::Black);
	highscore_text.setCharacterSize(30);
	highscore_text.setPosition(((float)window_width - highscore_text.getLocalBounds().width) / 2.f, float(window_height) / 10.f);


	sf::Text hs_title;
	hs_title.setFont(font);
	hs_title.setString("HIGHSCORE");
	hs_title.setFillColor(sf::Color::Black);
	hs_title.setCharacterSize(30);
	hs_title.setPosition((window_width - hs_title.getLocalBounds().width) / 2, highscore_text.getPosition().y - 35.f);
	
	sf::Text instr;
	instr.setFont(font);
	instr.setString("PRESS  SPACE  KEY  TO  PLAY");
	instr.setFillColor(sf::Color::Black);
	instr.setCharacterSize(20);
	instr.setPosition((window_width - instr.getLocalBounds().width) / 2, window_height - 2 * sJumper.getLocalBounds().height);

	draw(title);
	draw(highscore_text);
	draw(hs_title);
	draw(instr);
}

void Interface::draw_end_texts()
{
	if (score_text.getString() == ' ')
		set_string_score_text("0");
	set_size_score_text(30);
	set_position_score_text((window_width -score_text.getLocalBounds().width) / 2, window_height / 2.f - 20.f);

	sf::Text hs_title;
	hs_title.setFont(font);
	hs_title.setString("HIGHSCORE");
	hs_title.setFillColor(sf::Color::Black);
	hs_title.setCharacterSize(30);
	hs_title.setPosition((window_width - hs_title.getLocalBounds().width) / 2, highscore_text.getPosition().y - 35.f);


	sf::Text cs_title;
	cs_title.setFont(font);
	cs_title.setString("YOUR  SCORE");
	cs_title.setFillColor(sf::Color::Black);
	cs_title.setCharacterSize(30);
	cs_title.setPosition((window_width - cs_title.getLocalBounds().width) / 2, score_text.getPosition().y - 35.f);

	sf::Text instr;
	instr.setFont(font);
	instr.setString("         PRESS  ENTER  KEY  TO  PLAY  AGAIN\n\n\n PRESS  ESCAPE  KEY  TO  CLOSE  THE  GAME");
	instr.setFillColor(sf::Color::Black);
	instr.setCharacterSize(20);
	instr.setPosition((window_width - instr.getLocalBounds().width) / 2, window_height - 2 * sJumper.getLocalBounds().height);
	
	draw(score_text);
	draw(highscore_text);
	draw(hs_title);
	draw(cs_title);
	draw(instr);
}



bool Interface::check_right_key()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
}

bool Interface::check_left_key()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
}

void Interface::draw(const sf::Sprite & s)
{
	app.draw(s);
}

void Interface::draw(const sf::Text & t)
{
	app.draw(t);
}

void Interface::draw_plats( const Group_of_Plats & gr) 
{
	for (unsigned int i = 0; i < gr.get_nr_of_plats(); i++)
	{
		if (typeid(*gr.get_member(i)) != typeid(OneJumpPlatform))
		{
			set_position_sPlatform(gr.get_member(i)->get_coord_x(), gr.get_member(i)->get_coord_y());
		}
		else if (!gr.get_member(i)->get_is_visited())
			set_position_sOneJumpPlatform(gr.get_member(i)->get_coord_x(), gr.get_member(i)->get_coord_y());
		else
			set_position_sOneJumpPlatform(-20, -20);

		draw(sPlatform);
		draw(sOneJumpPlatform);
	}
}

void Interface::draw_all(const Group_of_Plats & g)
{
	draw(sBackground);
	draw_plats(g);
	draw(score_text);
	draw(sJumper);
	draw(sOpponent);
}

void Interface::load_textures(std::string str1, std::string str2, std::string str3, std::string str4, std::string str5)
{
	if (!t1.loadFromFile(str1))
	{
		throw std::string("nie odnaleziono pliku z tekstura tla");
	}
	if (!t2.loadFromFile(str2))
	{
		throw std::string("nie odnaleziono pliku z tekstura platformy");
	}
	if (!t21.loadFromFile(str3))
	{
		throw std::string("nie odnaleziono pliku z tekstura kruszacej sie platformy");
	}
	
	if (!t3.loadFromFile(str4))
	{
		throw std::string("nie odnaleziono pliku z tekstura skoczka");
	}
	if (!t4.loadFromFile(str5))
	{
		throw std::string("nie odnaleziono pliku z tekstura przeciwnika");
	}
}

void Interface::assign_sprites()
{
	sBackground.setTexture(t1);
	sPlatform.setTexture(t2);
	sOneJumpPlatform.setTexture(t21);
	sJumper.setTexture(t3);
	sOpponent.setTexture(t4);
}

void Interface::load_fonts(std::string str)
{
	if (!font.loadFromFile(str))
	{
		throw std::string("nie odnaleziono pliku z czcionka");
	}
}

void Interface::set_default_score_text()
{
	score_text.setFont(font);
	score_text.setString(' ');
	score_text.setFillColor(sf::Color::Black);
	score_text.setPosition(0.f, 0.f);
}

void Interface::create_window(unsigned int width, unsigned int height)
{
	window_width = width;
	window_height = height;
	window_title = "Jynx Jump";
	app.create(sf::VideoMode(window_width, window_height), window_title, sf::Style::Titlebar | sf::Style::Close);
	app.setFramerateLimit(60);
}

void Interface::display_window()
{
	app.display();
}

bool Interface::pollEvent(sf::Event & e)
{
	return app.pollEvent(e);
}

void Interface::app_close()
{
	app.close();
}
