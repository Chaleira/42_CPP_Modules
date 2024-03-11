#ifndef A_HPP
# define A_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Base.hpp"

class A : public Base
{
	private:

	public:
		A();
		A(const A &copy);
		A &operator=(const A &copy);
		~A();
};

#endif
