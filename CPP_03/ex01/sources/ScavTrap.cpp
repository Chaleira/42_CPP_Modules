#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	name = "ScavTrap";
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap) : ClapTrap(scavTrap)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = scavTrap;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &scavTrap)
{
	// std::cout << "ScavTrap assignation operator called" << std::endl;
	this->name = scavTrap.name;
	this->hitPoints = scavTrap.hitPoints;
	this->energyPoints = scavTrap.energyPoints;
	this->attackDamage = scavTrap.attackDamage;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string Scavname) : ClapTrap(Scavname)
{
	std::cout << "ScavTrap name constructor called" << std::endl;
	this->name = Scavname;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

void ScavTrap::attack(std::string const &target)
{
	if (energyPoints == 0)
	{
		std::cout << "ScavTrap " << name << " has no energy points left!" << std::endl;
		return ;
	}
	if (hitPoints == 0)
	{
		std::cout << "ScavTrap " << name << " can't attack because it's dead!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << name << " attack " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
	energyPoints -= 1;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " has entered in Gate keeper mode" << std::endl;
}
