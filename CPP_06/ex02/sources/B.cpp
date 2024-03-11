#include "B.hpp"

B::B()
{
	std::cout << "B constructor called" << std::endl;
}

B::B(const B &copy)
{
	std::cout << "B copy constructor called" << std::endl;
	// Don't forget to copy the variables here
	*this = copy;
}

B &B::operator=(const B &copy)
{
	(void)copy;
	std::cout << "B operator= called" << std::endl;
	// Don't forget to copy the variables here
	return *this;
}

B::~B()
{
	std::cout << "B destructor called" << std::endl;
}
