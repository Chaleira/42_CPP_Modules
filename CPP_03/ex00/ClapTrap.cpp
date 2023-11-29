#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap default constructor called" << std::endl;
	name = "ClapTrap";
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& clapTrap)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = clapTrap;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& clapTrap)
{
	// std::cout << "ClapTrap assignation operator called" << std::endl;
	this->name = clapTrap.name;
	this->hitPoints = clapTrap.hitPoints;
	this->energyPoints = clapTrap.energyPoints;
	this->attackDamage = clapTrap.attackDamage;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string ClapName)
{
	std::cout << "ClapTrap parameter constructor called" << std::endl;
	this->name = ClapName;
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
}

void ClapTrap::attack(const std::string& target)
{
	if (energyPoints == 0)
	{
		std::cout << "ClapTrap " << name << " has no energy points left!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
	energyPoints -= 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints == 0)
	{
		std::cout << "ClapTrap " << name << " is already dead! That's disrespectful" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
	hitPoints -= amount;
	if (hitPoints < 0)
		hitPoints = 0;
	if (hitPoints == 0)
		std::cout << "ClapTrap " << name << " died!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (energyPoints == 0)
	{
		std::cout << "ClapTrap " << name << " has no energy points left!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << name << " is repaired by " << amount << " points!" << std::endl;
	hitPoints += amount;
	energyPoints -= 1;
}

