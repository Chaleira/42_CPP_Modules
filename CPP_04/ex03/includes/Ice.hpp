#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice(Ice const &copy);
		Ice &operator=(Ice const &copy);
		virtual ~Ice();


		virtual AMateria* clone() const;
};

#endif