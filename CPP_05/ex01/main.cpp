#include "Bureaucrat.hpp"
#include "Form.hpp"

int main (void)
{
	try
	{
		Form f("f", 1, 1);
		Bureaucrat a("a", 1);
		Bureaucrat b("b", 150);
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		f.beSigned(a);
		a.incrementGrade();
		std::cout << "I will not be printed" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "I will be printed" << std::endl;
	return 0;
}