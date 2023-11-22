#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		Fixed const x;
		Fixed const y;

	public:
		Point();
		~Point();
		Point(const Point& point);
		Point(const float x, const float y);
		Point& operator=(const Point& point);
		float getX(void) const;
		float getY(void) const;
};

	std::ostream& operator<<(std::ostream& os, const Point& point);
	bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif