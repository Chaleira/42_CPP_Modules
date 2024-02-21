#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main (void)
{
	std::cout << "Creating a Bureaucrat of tier 1 (highest) outside the try scope" << std::endl << std::endl;
	Bureaucrat outside_try_scope("i'm not inside try", 1);
	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Creating a form outside the try scope" << std::endl << std::endl;
	ShrubberyCreationForm outside_try_scope_form("outside_try_scope_form");
	std::cout << "------------------------------------------" << std::endl;
	try
	{
		std::cout << "Creating a Form of tier 1 (highest)" << std::endl << std::endl;
		RobotomyRequestForm f("f");
		std::cout << "------------------------------------------" << std::endl;
		std::cout << "Creating a Bureaucrat of tier 1 (highest)" << std::endl << std::endl;
		Bureaucrat a("a", 1);
		std::cout << "------------------------------------------" << std::endl;

		std::cout << "Creating a Bureaucrat of tier 150 (lowest)" << std::endl << std::endl;
		Bureaucrat b("b", 150);
		std::cout << "------------------------------------------" << std::endl;
		std :: cout << "Printing their names tiers" << std::endl << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << "------------------------------------------" << std::endl;
		std::cout << "Trying to sign the form with a Bureaucrat of tier 150 and check if signed is true" << std::endl << std::endl;
		b.signForm(f);
		std::cout << f.getSigned() << std::endl;
		std::cout << "------------------------------------------" << std::endl;
		std::cout << "Trying to execute a form not signed" << std::endl << std::endl;
		a.executeForm(f);
		std::cout << "------------------------------------------" << std::endl;
		std::cout << "Trying to sign the form with a Bureaucrat of tier 1 and check if signed is true" << std::endl << std::endl;
		a.signForm(f);
		std::cout << f.getSigned() << std::endl;
		std::cout << "------------------------------------------" << std::endl;
		std::cout << "Trying to execute a form signed with a bureacrat of tier 150" << std::endl << std::endl;
		b.executeForm(f);
		std::cout << "------------------------------------------" << std::endl;
		std::cout << "Trying to execute a form signed with a bureacrat of tier 1" << std::endl << std::endl;
		a.executeForm(f);
		std::cout << "------------------------------------------" << std::endl;
		std::cout << "Trying to create a Bureaucrat of tier 0" << std::endl << std::endl;
		a.incrementGrade();
		std::cout << "I will not be printed" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "------------------------------------------" << std::endl;
		std::cout << "Printing execptions" << std::endl << std::endl;
		std::cout << e.what() << std::endl;
		std::cout << "------------------------------------------" << std::endl;
	}
	std::cout << "I will be printed" << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Destroying the Bureaucrat outside of the try scope" << std::endl << std::endl;
	return 0;
}