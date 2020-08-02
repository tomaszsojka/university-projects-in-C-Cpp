#ifndef DRAWABLE_OBJ_H
#define DRAWABLE_OBJ_H
template <typename T>
class Drawable_Obj
{
protected:
	float coord_x, coord_y;
	static float width, height;
public:
	Drawable_Obj();

	~Drawable_Obj();

	float get_coord_x() const;
	float get_coord_y() const;
	static float get_width();
	static float get_height();

	void set_coord_x(float x);
	void set_coord_y(float y);
};
template<typename T> float Drawable_Obj<T>::width(0); // tak tez mozna
template<typename T> float Drawable_Obj<T>::height = 0;

template<typename T>
inline Drawable_Obj<T>::Drawable_Obj()
{
}

template<typename T>
inline Drawable_Obj<T>::~Drawable_Obj()
{
}

template<typename T>
inline float Drawable_Obj<T>::get_coord_x() const
{
	return coord_x;
}

template<typename T>
inline float Drawable_Obj<T>::get_coord_y() const
{
	return coord_y;
}

template<typename T>
inline float Drawable_Obj<T>::get_width()
{
	return width;
}

template<typename T>
inline float Drawable_Obj<T>::get_height()
{
	return height;
}

template<typename T>
inline void Drawable_Obj<T>::set_coord_x(float x)
{
	coord_x = x;
}

template<typename T>
inline void Drawable_Obj<T>::set_coord_y(float y)
{
	coord_y = y;
}


#endif // !DRAWABLE_OBJ_H