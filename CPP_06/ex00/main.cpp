#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <string>

int main (int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./convert [value]" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}