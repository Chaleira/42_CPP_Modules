#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main (void)
{
	try {
		RobotomyRequestForm f("home");
		ShrubberyCreationForm f2("main");
		Bureaucrat a("a", 15);
		a.signForm(f);
		a.executeForm(f);
		a.signForm(f2);
		a.executeForm(f2);
	}
	catch (std::exception & e)
	{	std::cout << e.what() << std::endl; }
	return 0;
}