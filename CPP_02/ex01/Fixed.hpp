#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

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
		Fixed(const int value);
		Fixed(const float value);
		float toFloat(void) const;
		int toInt( void ) const;
};
	std::ostream& operator<<(std::ostream& out, const Fixed& fp);


#endif