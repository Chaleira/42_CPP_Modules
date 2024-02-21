#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor" << std::endl;
	_forms_name[0] = "shrubbery creation";
	_forms_name[1] = "robotomy request";
	_forms_name[2] = "presidential pardon";
}

Intern::Intern(const Intern &copy)
{
	std::cout << "Intern copy constructor" << std::endl;
	*this = copy;
}

Intern::~Intern()
{
	std::cout << "Intern destructor" << std::endl;
}

Intern &Intern::operator=(const Intern &copy)
{
	std::cout << "Intern assignation operator" << std::endl;
	(void)copy;
	return (*this);
}

const char* Intern::FormNotFoundException::what() const throw()
{
	return ("Form not found");
}

AForm *Intern::makeForm(std::string form, std::string target)
{
	try {
		int index = 3;
		for (int i = 0; i < 3; i++)
		{
			if (form == _forms_name[i])
			{
				std::cout << "Intern creates " << form << std::endl;
				index = i;
			}
		}
		switch (index)
		{
		case 0:
			return (new ShrubberyCreationForm(target));
		case 1:
			return (new RobotomyRequestForm(target));
		case 2:
			return (new PresidentialPardonForm(target));	
		default:
			throw FormNotFoundException();
		}
	}
	catch (std::exception & e)
	{
		std::cout << "Intern failed to create " << form << " because " << e.what() << std::endl;
		return NULL;
	}
}
