#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main (void)
{
	try {
		RobotomyRequestForm f("home");
		Bureaucrat a("a", 15);
		a.signForm(f);
		a.executeForm(f);
	}
	catch (std::exception & e)
	{	std::cout << e.what() << std::endl; }
	return 0;
}