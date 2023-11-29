#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	Animal abc;
	delete j;//should not create a leak
	delete i;
	std::cout << "---------------------" << std::endl;
	Animal *farm[10];
	for (int in = 0; in < 10; in++)
	{
		std::cout << in << ": ";
		if (in < 5)
			farm[in] = new Cat();
		else
			farm[in] = new Dog();
		farm[in]->makeSound();
	}
	for (int in = 0; in < 10; in++)
	{
		delete farm[in];
	}
	std::cout << "---------------------" << std::endl;
	Cat albert;
	albert.setIdeas("Albert's idea");
	albert.showIdeas();
	Cat copy(albert);
	std::cout << "copy type: " <<copy.getType() << std::endl;
	copy.showIdeas();
	copy.setIdeas("Copy's idea");
	copy.showIdeas();
	albert.showIdeas();
	Cat silly = albert;
	silly.showIdeas();
	silly.setIdeas("Silly's idea");
	silly.showIdeas();
	albert.showIdeas();
	return (0);
}