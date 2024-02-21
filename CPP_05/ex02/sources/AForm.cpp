#include "AForm.hpp"

AForm::AForm():
_name("Form"), _signed(false), _signGrade(150), _execGrade(150)
{
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string name, int signGrade, int execGrade):
_name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	std::cout << "AForm parameter constructor called" << std::endl;
	if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &copy):
_name(copy._name), _signed(copy._signed), _signGrade(copy._signGrade), _execGrade(copy._execGrade)
{
	std::cout << "AForm copy constructor called" << std::endl;
	*this = copy;
}

AForm &AForm::operator=(const AForm &copy)
{
	std::cout << "AForm assignation operator called" << std::endl;
	_signed = copy._signed;
	return (*this);
}

AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
}

std::string AForm::getName() const
{
	return _name;
}

bool AForm::getSigned() const
{
	return _signed;
}

int AForm::getSignGrade() const
{
	return _signGrade;
}

int AForm::getExecGrade() const
{
	return _execGrade;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _signGrade)
		throw AForm::GradeTooLowException();
	_signed = true;
	std::cout << "Bureaucrat " << bureaucrat.getName() << " signed form " << _name << std::endl;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed";
}

std::ostream& operator<<(std::ostream &out, const AForm &form)
{
	out << "Form " << form.getName() << " is ";
	if (form.getSigned())
		out << "signed";
	else
		out << "not signed";
	out << " and requires grade " << form.getSignGrade() << " to sign and grade " << form.getExecGrade() << " to execute";
	return (out);
}
