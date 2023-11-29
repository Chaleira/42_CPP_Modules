#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main (void)
{
	FragTrap fragTrap;

	fragTrap.takeDamage(20);
	fragTrap.takeDamage(20);
	fragTrap.takeDamage(20);
	fragTrap.takeDamage(20);
	fragTrap.takeDamage(20);
	fragTrap.takeDamage(1);
	fragTrap.highFivesGuys();
	return (0);
}