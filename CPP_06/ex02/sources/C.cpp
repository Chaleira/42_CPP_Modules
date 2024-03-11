#include "C.hpp"

C::C()
{
	std::cout << "C constructor called" << std::endl;
}

C::C(const C &copy)
{
	std::cout << "C copy constructor called" << std::endl;
	// Don't forget to copy the variables here
	*this = copy;
}

C &C::operator=(const C &copy)
{
	(void)copy;
	std::cout << "C operator= called" << std::endl;
	// Don't forget to copy the variables here
	return *this;
}

C::~C()
{
	std::cout << "C destructor called" << std::endl;
}
