#include "Draw.h"
#include <random>
#include <chrono>

float Draw::get_coord_x() const
{
	return coord_x;
}

float Draw::get_coord_y() const
{
	return coord_y;
}

int Draw::get_int_nr() const
{
	return int_nr;
}

void Draw::coordinates_draw(float inferior_x, float superior_x, float inferior_y, float superior_y)
{
	auto _time = std::chrono::system_clock::now();
	auto interval = _time.time_since_epoch();
	std::default_random_engine engine;
	std::uniform_real_distribution <float> distribution_x(inferior_x, superior_x);
	std::uniform_real_distribution <float> distribution_y(inferior_y, superior_y);//270); // odleglosci na jakie da sie wskoczyc
	engine.seed(interval.count());
	coord_x = distribution_x(engine);
	coord_y = distribution_y(engine);
}

void Draw::integer_draw(int inferior, int superior)
{
	auto _time = std::chrono::system_clock::now();
	auto interval = _time.time_since_epoch();
	std::default_random_engine engine;
	std::uniform_int_distribution <int> distribution(inferior, superior);
	engine.seed(interval.count());
	int_nr = distribution(engine);
}
