#include <iostream>

int main(void)
{
	std::string s	= "HI THIS IS BRAIN";
	std::string* p	= &s;
	std::string& a	= s;

	std::cout << &s << std::endl;
	std::cout << p << std::endl;
	std::cout << &a << std::endl;

	std::cout << std::endl;

	std::cout << s << std::endl;
	std::cout << *p << std::endl;
	std::cout << a << std::endl;

	return 0;
}
