#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
private:

	int					fixedNumberValue;
	static const int	fractionalBits = 8;

public:
	Fixed();
	~Fixed();
	Fixed(const Fixed& fixed);
	Fixed& operator=(const Fixed& fixed);
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif