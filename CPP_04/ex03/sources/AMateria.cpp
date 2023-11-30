#include "AMateria.hpp"

AMateria::AMateria()
{
	// std::cout << "Abstract Materia default constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	// std::cout << "Abstract Materia constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &copy)
{
	// std::cout << "Abstract Materia copy constructor called" << std::endl;
	_type = copy._type;
}

AMateria::~AMateria()
{
	// std::cout << "Abstract Materia destructor called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &copy)
{
	// std::cout << "Abstract Materia assignation operator called" << std::endl;
	if (this == &copy)
		return (*this);
	this->_type = copy._type;
	return (*this);
}

std::string const & AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	// std::cout << "Abstract Materia use function called" << std::endl;
	if (this->_type == "cure")
		std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	else if (this->_type == "ice")
		std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
