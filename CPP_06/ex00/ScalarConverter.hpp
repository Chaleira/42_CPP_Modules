#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cmath>
#include <climits>

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