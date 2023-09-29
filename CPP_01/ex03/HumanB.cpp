#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	std::cout << "HumanB constructor was called" << std::endl;
	this->name = name;
}

HumanB::~HumanB()		
{
	std::cout << "HumanB destructor was called" << std::endl;
}

void HumanB::attack()
{
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}