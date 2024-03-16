#include "RPN.hpp"

RPN::RPN()
{
	std::cout << "RPN constructor called" << std::endl;
}

RPN::RPN(const RPN &copy)
{
	std::cout << "RPN copy constructor called" << std::endl;
	// Don't forget to copy the variables here
	*this = copy;
}

RPN &RPN::operator=(const RPN &copy)
{
	(void)copy;
	std::cout << "RPN operator= called" << std::endl;
	// Don't forget to copy the variables here
	return *this;
}

RPN::~RPN()
{
	std::cout << "RPN destructor called" << std::endl;
}
