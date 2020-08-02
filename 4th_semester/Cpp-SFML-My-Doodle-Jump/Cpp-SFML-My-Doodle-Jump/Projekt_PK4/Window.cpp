#include "Window.h"

Window::Window(unsigned int w_width, unsigned int w_height)
{
	window_width = w_width;
	window_height = w_height;
	sensor_y = w_width / 2.6;
}

Window::Window(unsigned int w_width, unsigned int w_height, unsigned int s_y) : Window(w_width, w_height)
{
	sensor_y = s_y;
}

unsigned int Window::get_window_width() const
{
	return window_width;
}

unsigned int Window::get_window_height() const
{
	return window_height;
}

unsigned int Window::get_sensor_y() const
{
	return sensor_y;
}
