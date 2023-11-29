#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->brain = new Brain(*copy.brain);
}

Dog &Dog::operator=(const Dog &copy)
{
	std::cout << "Dog assignation operator called" << std::endl;
	if (this != &copy)
	{
		this->type = copy.type;
		delete this->brain;
		this->brain = new Brain(*copy.brain);
	}
	return (*this);
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Wof Wof!" << std::endl;
}

void Dog::setIdeas(std::string idea)
{
	this->brain->setIdeas(idea);
}

void Dog::showIdeas() const
{
	std::cout << "Dog's ideas: " << this->brain->getIdeas() << std::endl;
}
