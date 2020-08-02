#include "Score_Counter.h"
#include <fstream>

int Score_Counter::highscore = 0;

Score_Counter::Score_Counter()
{
	current_score = 0;
	current_highscore = 0;
}

float Score_Counter::get_cur_score() const
{
	return current_score;
}

void Score_Counter::set_cur_score(float c_s)
{
	current_score = c_s;
}

int Score_Counter::get_highscore()
{
	return highscore;
}

void Score_Counter::load_highscore(std::string filename)
{
	std::ifstream file(filename);
	if (!file)
	{
		throw std::string("nie odnaleziono pliku z najlepszym wynikiem");;
	}
	else
	{
		//DODAJ SPRAWDZENIE
		file >> highscore;
		file.close();
	}
}

void Score_Counter::save_highscore(std::string filename)
{
	if (current_score > highscore)
	{
		std::ofstream file(filename);
		file << current_score;
		file.close();
	}
}
