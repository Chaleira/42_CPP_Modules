#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"
# include <iostream>

class Point
{
	private:
		Fixed const x;
		Fixed const y;

	public:

		Point();
		Point(const Point& point);
		Point& operator=(const Point& point);
		~Point();
		Point(const float x, const float y);
		float getX(void) const;
		float getY(void) const;
};

	std::ostream& operator<<(std::ostream& os, const Point& point);

#endif