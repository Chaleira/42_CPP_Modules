#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	dima_name = "DiamondTrap";
	ClapTrap::name = dima_name + "_clap_name";
	hitPoints = FragTrap::hitPoints;
	energyPoints = ScavTrap::energyPoints;
	attackDamage = 30;
} 

DiamondTrap::DiamondTrap(const DiamondTrap& diamondTrap) : ClapTrap(diamondTrap), FragTrap(diamondTrap), ScavTrap(diamondTrap)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	ClapTrap::name = dima_name + "_clap_name";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& diamondTrap)
{
	std::cout << "DiamondTrap assignation operator called" << std::endl;
	this->dima_name = diamondTrap.dima_name;
	this->hitPoints = diamondTrap.hitPoints;
	this->energyPoints = diamondTrap.energyPoints;
	this->attackDamage = diamondTrap.attackDamage;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string Dimaname)
{
	std::cout << "DiamondTrap parameter constructor called" << std::endl;
	this->dima_name = Dimaname;
	ClapTrap::name = this->dima_name + "_clap_name";
	this->hitPoints = this->FragTrap::hitPoints;
	this->energyPoints = this->ScavTrap::energyPoints;
	this->attackDamage = 30;
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap name: " << dima_name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::name << std::endl;
}
