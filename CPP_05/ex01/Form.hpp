#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	bool _signed;
	const int _signGrade;
	const int _execGrade;

public:

	Form();
	Form(const std::string name, int signGrade, int execGrade);
	Form(const Form &copy);
	Form &operator=(const Form &copy);
	~Form();

	std::string getName() const;
	bool getSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;
	void beSigned(const Bureaucrat &bureaucrat);

	class GradeTooHighException : public std::exception
	{
	public:
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream &out, const Form &form);

#endif
