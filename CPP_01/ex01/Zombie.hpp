#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <vector>

class Zombie
{
private:
	std::string name;
public:
	Zombie();
	~Zombie();
	void setName(std::string);
	void announce(void);
	Zombie* zombieHorde(int N, std::string name);
};

#endif