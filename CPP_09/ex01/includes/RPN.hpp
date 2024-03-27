#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <exception>
# include <stack>
# include <sstream>

class RPN
{
	private:
		static std::stack<double> _stack;
		static double _result;

		RPN();
		RPN(const RPN &copy);
		RPN &operator=(const RPN &copy);
		~RPN();
		static void do_math(char c);

	public:
		static void calculate(std::string str);
};

#endif
