#include "easyfind.hpp" 
#include <iostream>
#include <vector>

int main (void)
{
	std::vector<int> v;
	int value;

	for (int i = 0; i < 50; i++)
		v.push_back(i);
	try {
		value = easyfind(v, 42);
		std::cout << "Value: " << value << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try {
		value = easyfind(v, 100);
		std::cout << "Value: " << value << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	return 0;
}
