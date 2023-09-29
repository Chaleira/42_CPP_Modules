#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon)
{
	std::cout << "HumanA constructor was called" << std::endl;
	this->name = name;
	this->weapon = &weapon;
}

HumanA::~HumanA()
{
	std::cout << "HumanA destructor was called" << std::endl;
}

void HumanA::attack()
{
	std::cout << this->name << " attacks with their " << weapon->getType() << std::endl;
}