#ifndef B_HPP
# define B_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Base.hpp"

class B : public Base
{
	private:

	public:
		B();
		B(const B &copy);
		B &operator=(const B &copy);
		~B();
};

#endif
