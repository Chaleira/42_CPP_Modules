#include "Zombie.hpp"

Zombie* Zombie::zombieHorde(int N, std::string name)
{
	Zombie* zombiesArray = new Zombie[N];

    for (int i = 0; i < N; i++)
	{
        zombiesArray[i].setName(name);
    }
	return zombiesArray;
}