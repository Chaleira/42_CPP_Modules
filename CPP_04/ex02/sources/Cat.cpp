#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->brain = new Brain(*copy.brain);
}

Cat &Cat::operator=(const Cat &copy)
{
	std::cout << "Cat assignation operator called" << std::endl;
	if (this != &copy)
	{
		this->type = copy.type;
		delete this->brain;
		this->brain = new Brain(*copy.brain);
	}
	return (*this);
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Miaou Miaou!" << std::endl;
}

void Cat::setIdeas(std::string idea)
{
	this->brain->setIdeas(idea);
}

void Cat::showIdeas() const
{
	std::cout << "Cat's ideas: " << this->brain->getIdeas() << std::endl;
}

