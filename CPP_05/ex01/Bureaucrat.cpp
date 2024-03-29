#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():
_name("Bureaucrat"), _grade(150)
{
	std::cout << "Bureaucrat default constructor" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade):
_name(name), _grade(grade)
{
	std::cout << "Bureaucrat parameter constructor" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy):
_name(copy._name), _grade(copy._grade)
{
	std::cout << "Bureaucrat copy constructor" << std::endl;
	*this = copy;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
	std::cout << "Bureaucrat assignation operator" << std::endl;
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

void Bureaucrat::signForm(Form &form) const
{
	try {
		form.beSigned(*this);
	}
	catch (std::exception & e)
	{
		std::cout << _name << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
	}
}
