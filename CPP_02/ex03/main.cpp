#include <iostream>
#include "Point.hpp"

int main( void )
{
	Point a(-5, 0);
	Point b(5, 0);
	Point c(0, 10);
	Point point(0, 0);

	if (bsp(a, b, c, point))
		std::cout << point << " is inside the triangle" << std::endl;
	else
		std::cout << point << " is outside the triangle" << std::endl;
}
