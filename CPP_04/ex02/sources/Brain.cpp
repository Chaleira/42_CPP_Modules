#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(Brain const &other)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
    	ideas[i] = other.ideas[i];
}

Brain &Brain::operator=(Brain const &other)
{
	std::cout << "Brain assignation operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

std::string Brain::getIdeas() const
{
	return (this->ideas[1]);
}

void Brain::setIdeas(std::string idea)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = idea;
}
