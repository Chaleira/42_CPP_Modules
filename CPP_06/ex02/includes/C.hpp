#ifndef C_HPP
# define C_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Base.hpp"

class C : public Base
{
	private:

	public:
		C();
		C(const C &copy);
		C &operator=(const C &copy);
		~C();
};

#endif
