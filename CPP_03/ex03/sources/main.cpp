#include "DiamondTrap.hpp"

int main (void)
{
	DiamondTrap diamondTrap("flopy");

	diamondTrap.printStatus();
	diamondTrap.attack("target");
	diamondTrap.whoAmI();
	diamondTrap.highFivesGuys();
	diamondTrap.guardGate();
	diamondTrap.takeDamage(10);
	diamondTrap.beRepaired(10);
	diamondTrap.takeDamage(90);
	diamondTrap.takeDamage(100);
	diamondTrap.beRepaired(100);
	diamondTrap.takeDamage(45);
	diamondTrap.printStatus();
	DiamondTrap diamondTrap2(diamondTrap);
	diamondTrap2.printStatus();
	diamondTrap2.takeDamage(10);
	DiamondTrap diamondTrap3;
	diamondTrap3 = diamondTrap2;
	diamondTrap3.printStatus();
	return (0);
}