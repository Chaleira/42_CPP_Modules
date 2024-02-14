#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	private:
		std::string _forms_name[3];

	public:
		Intern();
		Intern(const Intern &copy);
		~Intern();
	
		Intern &operator=(const Intern &copy);
	
		AForm *makeForm(std::string form, std::string target);
	
		class FormNotFoundException : public std::exception
		{
			virtual const char *what() const throw();
		};
};

#endif