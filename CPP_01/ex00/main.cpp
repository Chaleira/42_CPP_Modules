#include "Zombie.hpp"

int main(void)
{
	Zombie* mikeZombie;
	Zombie alexZombie("Alex");
	mikeZombie = alexZombie.newZombie("Mike");
	alexZombie.randomChump("Peter");
	mikeZombie->announce();
	alexZombie.announce();
	delete mikeZombie;
}