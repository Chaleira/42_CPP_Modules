#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <exception>

class RPN
{
	private:

	public:
		RPN();
		RPN(const RPN &copy);
		RPN &operator=(const RPN &copy);
		~RPN();
};

#endif
