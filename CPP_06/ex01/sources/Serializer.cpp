#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Serializer constructor called" << std::endl;
}

Serializer::Serializer(const Serializer &copy)
{
	std::cout << "Serializer copy constructor called" << std::endl;
	// Don't forget to copy the variables here
	*this = copy;
}

Serializer &Serializer::operator=(const Serializer &copy)
{
	(void)copy;
	std::cout << "Serializer operator= called" << std::endl;
	// Don't forget to copy the variables here
	return *this;
}

Serializer::~Serializer()
{
	std::cout << "Serializer destructor called" << std::endl;
}

uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
