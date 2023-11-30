#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	// std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(const Ice &copy) : AMateria(copy)
{
	// std::cout << "Ice copy constructor called" << std::endl;
	*this = copy;
}


Ice &Ice::operator=(const Ice &copy)
{
	// std::cout << "Ice assignation operator called" << std::endl;
	if (this == &copy)
		return (*this);
	this->_type = copy._type;
	return (*this);
}

Ice::~Ice()
{
	std::cout << "Ice destructor called" << std::endl;
}

AMateria *Ice::clone() const
{
	// std::cout << "Ice clone function called" << std::endl;
	return (new Ice(*this));
}
