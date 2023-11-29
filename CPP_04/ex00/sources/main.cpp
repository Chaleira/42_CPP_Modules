#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal *meta = new Animal();
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();
	Animal *AnimalPtr;
	Dog TestDog;
	Cat TestCat;
	Animal TestAnimal;
	const WrongAnimal *wrongCat = new WrongCat();

	std::cout << std::endl;
	std::cout << "meta->getType(): " << meta->getType() << std::endl;
	std::cout << "dog->getType(): " << dog->getType() << std::endl;
	std::cout << "cat->getType(): " << cat->getType() << std::endl;
	std::cout << "wrongCat->getType(): " << wrongCat->getType() << std::endl;
	std::cout << std::endl;
	dog->makeSound();
	cat->makeSound();
	meta->makeSound();
	wrongCat->makeSound();
	std::cout << std::endl;
	AnimalPtr = &TestDog;
	AnimalPtr->makeSound();
	AnimalPtr = &TestCat;
	AnimalPtr->makeSound();
	AnimalPtr = &TestAnimal;
	AnimalPtr->makeSound();
	std::cout << std::endl;
	delete meta;
	delete dog;
	delete cat;
	delete wrongCat;
	return (0);
}