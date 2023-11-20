#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : fixedNumberValue(other.fixedNumberValue)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	if (this != &other)
        fixedNumberValue = other.fixedNumberValue;
	return *this;
}

int Fixed::getRawBits(void) const
{	
	return fixedNumberValue;
}

void Fixed::setRawBits(int const raw)
{
	this->fixedNumberValue = raw;
}