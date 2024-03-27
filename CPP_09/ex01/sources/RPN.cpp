#include "RPN.hpp"

std::stack<double> RPN::_stack;
double RPN::_result;

RPN::RPN()
{
	std::cout << "RPN constructor called" << std::endl;
}

RPN::RPN(const RPN &copy)
{
	std::cout << "RPN copy constructor called" << std::endl;
	// Don't forget to copy the variables here
	*this = copy;
}

RPN &RPN::operator=(const RPN &copy)
{
	(void)copy;
	std::cout << "RPN operator= called" << std::endl;
	// Don't forget to copy the variables here
	return *this;
}

RPN::~RPN()
{
	std::cout << "RPN destructor called" << std::endl;
}

void RPN::do_math(char c)
{
	double hold = _stack.top();
	_stack.pop();
	switch (c)
	{
		case '+':
			_result = _stack.top() + hold;
			break;
		case '-':
			_result = _stack.top() - hold;
			break;
		case '*':
			_result = _stack.top() * hold;
			break;
		case '/':
			if (hold == 0)
				throw std::runtime_error("Division by zero");
			_result = _stack.top() / hold;
			break;
	}
	_stack.pop();
	_stack.push(_result);
}

void RPN::calculate(std::string str)
{
	std::stringstream ss(str);
	std::string op;
	while (ss >> op)
	{
		if (std::isdigit(op[0]))
			_stack.push(op[0] - '0');
		else if (std::string("+-*/").find(op[0]) != std::string::npos)
		{
			if (_stack.size() < 2)
			{
				std::cout << "Not enough numbers" << std::endl;
				return;
			}
			try {
				do_math(op[0]);
			}
			catch (std::exception &e)
			{
				std::cout << e.what() << std::endl;
				return;
			}
		}
		else
		{
			std::cout << "Invalid character" << std::endl;
			return;
		}
	}
	if (_stack.size() != 1)
		std::cout << "Too many numbers" << std::endl;
	else
		std::cout << _result << std::endl;
}