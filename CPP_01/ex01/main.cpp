#include "Zombie.hpp"

int main(void)
{
	Zombie zombie;
	Zombie *horde;
	int		N = 10;

	zombie.setName("Zombie");
	zombie.announce();
	horde = zombie.zombieHorde(N, "Horde");
	for (int i = 0; i < N; i++)
	{
		std::cout << i + 1 << " : ";
		horde[i].announce();
	}
	delete[] horde;
	return 0;
}
