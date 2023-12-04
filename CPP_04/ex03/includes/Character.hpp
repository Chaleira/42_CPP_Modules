#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		std::string _name;
		AMateria *_inventory[4];
		int _count;
		int _droped_count;
		AMateria **_droped;
		AMateria **_copyDroped(AMateria *m);
		bool _isInDroped(AMateria *m);
		bool _isInInv(AMateria *m);

	public:
		Character();
		Character(std::string const &name);
		Character(Character const &copy);
		Character &operator=(Character const &copy);
		virtual ~Character();

		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
};

#endif