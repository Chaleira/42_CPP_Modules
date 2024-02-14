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

AForm *delete_array(AForm *forms_class[3], int i)
{
	delete forms_class[i - 1];
	delete forms_class[i + 1];
	return (forms_class[i]);
}

AForm *Intern::makeForm(std::string form, std::string target)
{
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
