#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	std::cout << "Bureaucrat default constructor" << std::endl;
	_name = "Bureaucrat";
	_grade = 150;
}

Bureaucrat::Bureaucrat(const char *name, int grade)
{
	std::cout << "Bureaucrat parameter constructor" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
	_name = name;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	std::cout << "Bureaucrat copy constructor" << std::endl;
	*this = copy;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
	std::cout << "Bureaucrat assignation operator" << std::endl;
	_name = copy._name;
	_grade = copy._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor" << std::endl;
}

std::string Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::incrementGrade()
{
	if (_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (out);
}

void Bureaucrat::signForm(AForm &form) const
{
	if (form.getSignGrade() < _grade)
	{
		std::cout << _name << " cannot sign " << form.getName() << " because his grade is too low" << std::endl;
		throw Bureaucrat::GradeTooLowException();
	}
	form.beSigned(*this);
	std::cout << _name << " signed " << form.getName() << std::endl;
}

void Bureaucrat::executeForm(const AForm &form) const
{
	try
	{
		std::cout << _name << " executes " << form.getName() << std::endl;
		form.execute(*this);
	}
	catch (std::exception &e)
	{
		std::cout << _name << " cannot execute " << form.getName() << " because " << e.what() << std::endl;
	}
}
