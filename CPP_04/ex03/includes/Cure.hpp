#ifndef CURSE_HPP
# define CURSE_HPP

# include <iostream>
# include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure(Cure const &copy);
		Cure &operator=(Cure const &copy);
		virtual ~Cure();

		virtual AMateria* clone() const;
};

#endif