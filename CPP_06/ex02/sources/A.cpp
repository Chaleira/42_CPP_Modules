#include "A.hpp"

A::A()
{
	std::cout << "A constructor called" << std::endl;
}

A::A(const A &copy)
{
	std::cout << "A copy constructor called" << std::endl;
	// Don't forget to copy the variables here
	*this = copy;
}

A &A::operator=(const A &copy)
{
	(void)copy;
	std::cout << "A operator= called" << std::endl;
	// Don't forget to copy the variables here
	return *this;
}

A::~A()
{
	std::cout << "A destructor called" << std::endl;
}
