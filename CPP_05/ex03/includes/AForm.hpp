#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const char *_name;
	bool _signed;
	int _signGrade;
	int _execGrade;

protected:
	AForm();
	AForm(const char *name, int signGrade, int execGrade);
	AForm(const AForm &copy);
	AForm &operator=(const AForm &copy);

public:
	virtual ~AForm();

	std::string getName() const;
	bool getSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;
	void beSigned(const Bureaucrat &bureaucrat);
	virtual void execute(Bureaucrat const &executor) const = 0;

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

	class FormNotSignedException : public std::exception
	{
	public:
		const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream &out, const AForm &form);

#endif