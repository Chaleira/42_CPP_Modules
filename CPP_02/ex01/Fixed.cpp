#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fixedNumberValue = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
        fixedNumberValue = other.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const
{	
	std::cout << "getRawBits member function called" << std::endl;
	return fixedNumberValue;
}

void Fixed::setRawBits(int const raw)
{
	this->fixedNumberValue = raw;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixedNumberValue = value << fractionalBits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixedNumberValue = roundf(value * (1 << fractionalBits));
}

float Fixed::toFloat(void) const
{
	
}

int Fixed::toInt(void) const
{

}

