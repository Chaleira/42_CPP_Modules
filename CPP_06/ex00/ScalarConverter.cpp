#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	*this = copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
	(void)copy;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

const char *ScalarConverter::ImpossibleException::what() const throw()
{
	return "impossible";
}

const char *ScalarConverter::NonDisplayableException::what() const throw()
{
	return "Non displayable";
}

void convertToChar(std::string str)
{
	try {
		if (str.length() == 1 && !isdigit(str[0]))
		{
			std::cout << "char: '" << str << "'" << std::endl;
			return;
		}
		std::cout << "char: ";
		if (((str[0] == '+' || str[0] == '-') && !isdigit(str[1])) || (str.length() >= 2 && !isdigit(str[1])))
			throw ScalarConverter::ImpossibleException();
		double dvalue = atof(str.c_str());
		if (dvalue < 0 || dvalue > 127 || std::isnan(dvalue) || std::isinf(dvalue))
			throw ScalarConverter::ImpossibleException();
		if (std::isprint(static_cast<char>(dvalue)))
			std::cout << "'" << static_cast<char>(dvalue) << "'" << std::endl;
		else
			throw ScalarConverter::NonDisplayableException();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void convertToInt(std::string str)
{
	try {
		if (str.length() == 1 && !isdigit(str[0]))
		{
			std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
			return;
		}
		std::cout << "int: ";
		if (((str[0] == '+' || str[0] == '-') && !isdigit(str[1])) || (str.length() >= 2 && !isdigit(str[1])))
			throw ScalarConverter::ImpossibleException();
		double dvalue = atof(str.c_str());
		if (dvalue < INT_MIN || dvalue > INT_MAX || std::isnan(dvalue) || std::isinf(dvalue))
			throw ScalarConverter::ImpossibleException();
		std::cout << static_cast<int>(dvalue) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void convertToFloat(std::string str)
{
	try {
		if (str.length() == 1 && !isdigit(str[0]))
		{
			std::cout << "float: " << static_cast<float>(str[0]) << ".0f" << std::endl;
			return;
		}
		std::cout << "float: ";
		if (((str[0] == '+' || str[0] == '-') && !isdigit(str[1])) || (str.length() >= 2 && !isdigit(str[1])))
			throw ScalarConverter::ImpossibleException();
		double dvalue = atof(str.c_str());
		std::cout << static_cast<float>(dvalue);
		if (static_cast<float>(dvalue) - static_cast<int>(dvalue) == 0)
			std::cout << ".0";
		std::cout << "f" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void convertToDouble(std::string str)
{
	try {
		if (str.length() == 1 && !isdigit(str[0]))
		{
			std::cout << "double: " << static_cast<double>(str[0]) << ".0" << std::endl;
			return;
		}
		std::cout << "double: ";
		if (((str[0] == '+' || str[0] == '-') && !isdigit(str[1])) || (str.length() >= 2 && !isdigit(str[1])))
			throw ScalarConverter::ImpossibleException();
		double dvalue = atof(str.c_str());
		std::cout << dvalue;
		if (dvalue - static_cast<int>(dvalue) == 0)
			std::cout << ".0";
		std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void ScalarConverter::convert(std::string d)
{
	try {
		convertToChar(d);
		convertToInt(d);
		convertToFloat(d);
		convertToDouble(d);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}