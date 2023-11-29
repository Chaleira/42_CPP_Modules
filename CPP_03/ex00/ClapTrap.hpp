#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	private:
		std::string		name;
		int				hitPoints;
		int				energyPoints;
		int				attackDamage;
	
	public:
		ClapTrap();
		ClapTrap(const ClapTrap& clapTrap);
		ClapTrap& operator=(const ClapTrap& clapTrap);
		~ClapTrap();
		ClapTrap(std::string name);

		void attack(const std::string& target);
 		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif