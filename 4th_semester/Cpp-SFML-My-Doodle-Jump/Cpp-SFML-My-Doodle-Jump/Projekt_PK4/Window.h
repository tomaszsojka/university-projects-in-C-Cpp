#ifndef WINDOW_H
#define WINDOW_H

class Window
{
	unsigned int window_width, window_height;
	unsigned int sensor_y;
public:
	Window() = delete;
	Window(unsigned int w_width, unsigned int w_height);
	Window(unsigned int w_width, unsigned int w_height, unsigned int s_y);
	unsigned int get_window_width() const;
	unsigned int get_window_height() const;
	unsigned int get_sensor_y() const;
	~Window() = default;
};
#endif // !WINDOW_H


