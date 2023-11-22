#include "Fixed.hpp"

Fixed::Fixed()
{
	this->fixedNumberValue = 0;
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const Fixed& other)
{
	*this = other;
}

int Fixed::getRawBits(void) const
{	
	return fixedNumberValue;
}

void Fixed::setRawBits(int const raw)
{
	this->fixedNumberValue = raw;
}

Fixed::Fixed(const int value)
{
	this->fixedNumberValue = value << fractionalBits;
}

Fixed::Fixed(const float value)
{
	this->fixedNumberValue = roundf(value * (1 << fractionalBits));
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(fixedNumberValue) / (1 << fractionalBits);
}

int Fixed::toInt(void) const
{
	return fixedNumberValue >> fractionalBits;
}


Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
        fixedNumberValue = other.getRawBits();
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fp)
{
	out << fp.toFloat();
	return out;
}

Fixed& Fixed::operator*(const Fixed& fixed)
{
	this->fixedNumberValue = (fixedNumberValue * fixed.fixedNumberValue) >> fractionalBits;
	return *this;
}

Fixed& Fixed::operator+(const Fixed& fixed)
{
	this->fixedNumberValue = this->toFloat() + fixed.toFloat();
	return *this;
}

Fixed& Fixed::operator-(const Fixed& fixed)
{
	this->fixedNumberValue = this->toFloat() - fixed.toFloat();
	return *this;
}

Fixed& Fixed::operator/(const Fixed& fixed)
{
	this->fixedNumberValue = this->toFloat() / fixed.toFloat();
	return *this;
}

Fixed& Fixed::operator++(void)
{
	this->fixedNumberValue++;
	return *this;
}

Fixed& Fixed::operator--(void)
{
	this->fixedNumberValue--;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return tmp;
}

bool Fixed::operator>(const Fixed& fixed)
{
	return this->toFloat() > fixed.toFloat();
}

bool Fixed::operator<(const Fixed& fixed)
{
	return this->toFloat() < fixed.toFloat();
}

bool Fixed::operator>=(const Fixed& fixed)
{
	return this->toFloat() >= fixed.toFloat();
}

bool Fixed::operator<=(const Fixed& fixed)
{
	return this->toFloat() <= fixed.toFloat();
}

bool Fixed::operator==(const Fixed& fixed)
{
	return this->toFloat() == fixed.toFloat();
}

bool Fixed::operator!=(const Fixed& fixed)
{
	return this->toFloat() != fixed.toFloat();
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a.toFloat() < b.toFloat())
		return a;
	return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a.toFloat() > b.toFloat())
		return a;
	return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a.toFloat() < b.toFloat())
		return a;
	return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a.toFloat() > b.toFloat())
		return a;
	return b;
}
