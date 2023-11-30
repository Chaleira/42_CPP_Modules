#ifndef AMAETERIA_HPP
# define AMAETERIA_HPP

# include <iostream>
# include "Character.hpp"

class ICharacter;
class AMateria
{
	protected:
		std::string _type;

		AMateria();
		AMateria(const AMateria &copy);
		AMateria &operator=(const AMateria &copy);

	public:
		AMateria(std::string const & type);
		virtual ~AMateria();

		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif