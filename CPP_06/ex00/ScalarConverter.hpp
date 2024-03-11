#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cmath>
#include <climits>
#include <cfloat>

enum e_type
{
	CHAR = 1,
	INT = 2,
	FLOAT = 3,
	DOUBLE = 4,
	INVALID = 5
};
class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter &operator=(const ScalarConverter &copy);
		~ScalarConverter();

	public:
		static void convert(std::string value);

		class ImpossibleException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class NonDisplayableException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif