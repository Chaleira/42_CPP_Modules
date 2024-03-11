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

void printChar(int c)
{
	std::cout << "char: ";
	if (c < 0 || c > 127)
		std::cout << "impossible" << std::endl;
	else if (isprint(c))
		std::cout << "'" << static_cast<char>(c) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
}

void printInt(long num)
{
	std::cout << "int: ";
	if (num > INT_MAX || num < INT_MIN)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(num) << std::endl;
}

void printFloat(float num)
{
	std::cout << "float: ";
	if (num > FLT_MAX || num < -FLT_MAX)
		std::cout << "impossible" << std::endl;
	else if (num - static_cast<long long>(num) == 0)
		std::cout << static_cast<float>(num) << ".0f" << std::endl;
	else
		std::cout << static_cast<float>(num) << "f" << std::endl;
}

void printDouble(double num)
{
	std::cout << "double: ";
	if (num - static_cast<long long>(num) == 0)
		std::cout << static_cast<double>(num) << ".0" << std::endl;
	else
		std::cout << static_cast<double>(num) << std::endl;
}

int identifyType(std::string str)
{
	if (str == "nan" || str == "nanf" || str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff"
		|| str == "inff" || str == "inf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << str << std::endl;
		std::cout << "double: " << str << std::endl;
		return 6;
	}
	if (str.length() == 1 && !isdigit(str[0]))
		return CHAR;
	size_t i = 0;
	if (str[0] == '+' || str[0] == '-')
		i = 1;
	while (isdigit(str[i])  && i < str.length())
		i++;
	if (i == str.length())
		return INT;
	if (str[i] == '.')
	{
		i++;
		if (!str[i] || !isdigit(str[i]))
			return INVALID;
		while (isdigit(str[i]) && i < str.length())
			i++;
		if (str[i] == 'f' && i == str.length() - 1)
			return FLOAT;
		if (i == str.length())
			return DOUBLE;
	}
	return INVALID;
}

void convertToInt(std::string str)
{
	long num = atol(str.c_str());
	if (num > INT_MAX || num < INT_MIN)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
	else
	{
		printChar(num);
		printInt(num);
		printFloat(static_cast<float>(num));
		printDouble(static_cast<double>(num));
	
	}
}

void convertToFloat(std::string str)
{
	float num = atof(str.c_str());
	if (num > FLT_MAX || num < -FLT_MAX)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
	else
	{
		printChar(num);
		printInt(num);
		printFloat(num);
		printDouble(static_cast<double>(num));
	}
}

void ScalarConverter::convert(std::string d)
{
	int type = identifyType(d);

	switch (type)
	{
	case 1 :
		printChar(d[0]);
		printInt(static_cast<int>(d[0]));
		printFloat(static_cast<float>(d[0]));
		printDouble(static_cast<double>(d[0]));
		break;
	case 2 : {
		convertToInt(d);
		break;
	}
	case 3 :
		convertToFloat(d);
		break;
	case 4 :
		printChar(atof(d.c_str()));
		printInt(atof(d.c_str()));
		printFloat(atof(d.c_str()));
		printDouble(atof(d.c_str()));
		break;
	case 5:
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		break;
	default:
		break;
	}
	
}
