#include "Point.hpp"

Point::Point() : x(0), y(0)
{
}

Point::~Point()
{
}

Point::Point(const Point& point) : x(point.x), y(point.y)
{
}

Point::Point(const float x, const float y) : x(x), y(y)
{
}

Point& Point::operator=(const Point& point)
{
	(void)point;
	return (*this);
}

float Point::getX(void) const
{
	return (this->x.toFloat());
}

float Point::getY(void) const
{
	return (this->y.toFloat());
}


std::ostream& operator<<(std::ostream& os, const Point& point)
{
	os << "Point(" << point.getX() << ", " << point.getY() << ")";
	return (os);
}
