#ifndef DRAW_H
#define DRAW_H

class Draw
{
	float coord_x, coord_y;
	int int_nr;
public:
	Draw() = default;
	~Draw() = default;

	float get_coord_x() const;
	float get_coord_y() const;
	int get_int_nr() const;

	void coordinates_draw(float inferior_x, float superior_x, float inferior_y, float superior_y);
	void integer_draw(int inferior, int superior);
};
#endif // !DRAW_H