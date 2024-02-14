#include "Form.hpp"

Form::Form()
{
	std::cout << "Form default constructor" << std::endl;
	_name = "Form";
	_signed = false;
	_signGrade = 150;
	_execGrade = 150;
}

Form::Form(std::string name, int signGrade, int execGrade)
{
	std::cout << "Form parameter constructor" << std::endl;
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
	_name = name;
	_signed = false;
	_signGrade = signGrade;
	_execGrade = execGrade;
}

Form::Form(const Form &copy)
{
	std::cout << "Form copy constructor" << std::endl;
	*this = copy;
}

Form &Form::operator=(const Form &copy)
{
	std::cout << "Form assignation operator" << std::endl;
	_name = copy._name;
	_signed = copy._signed;
	_signGrade = copy._signGrade;
	_execGrade = copy._execGrade;
	return (*this);
}

Form::~Form()
{
	std::cout << "Form destructor" << std::endl;
}

std::string Form::getName() const
{
	return _name;
}

bool Form::getSigned() const
{
	return _signed;
}

int Form::getSignGrade() const
{
	return _signGrade;
}

int Form::getExecGrade() const
{
	return _execGrade;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	bureaucrat.signForm(*this);
	_signed = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

std::ostream& operator<<(std::ostream &out, const Form &form)
{
	out << "Form " << form.getName() << " is ";
	if (form.getSigned())
		out << "signed";
	else
		out << "not signed";
	out << " and requires grade " << form.getSignGrade() << " to sign and grade " << form.getExecGrade() << " to execute";
	return (out);
}
