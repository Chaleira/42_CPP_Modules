#include "Character.hpp"

Character::Character() : _name(), _inventory(), _count(0), _droped_count(0), _droped(NULL)
{
	// std::cout << "Character default constructor called" << std::endl;
}

Character::Character(std::string const &name) : _name(name), _inventory(), _count(0), _droped_count(0), _droped(NULL)
{
	// std::cout << "Character default constructor called" << std::endl;
}

Character::Character(const Character &copy) : _name(copy._name), _inventory(), _count(copy._count), _droped_count(copy._droped_count), _droped(copy._droped)
{
	// std::cout << "Character copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (copy._inventory[i])
			this->_inventory[i] = copy._inventory[i]->clone();
	}
}

Character &Character::operator=(const Character &copy)
{
	// std::cout << "Character assignation operator called" << std::endl;
	if (this == &copy)
		return (*this);
	this->_name = copy._name;
	this->_count = copy._count;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
		this->_inventory[i] = copy._inventory[i]->clone();
	}
	return (*this);
}

Character::~Character()
{
	// std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] && !_isInDroped(this->_inventory[i]))
			delete this->_inventory[i];
	}
	for (int i = 0; i < _droped_count; i++)
	{
		if (this->_droped[i])
			delete this->_droped[i];
	}
	delete [] _droped;
}

std::string const &Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria *m)
{
	if (m == NULL)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (!this->_inventory[i])
		{
			this->_inventory[i] = m;
			this->_count++;
			return ;
		}
	}
	if (!_isInDroped(m))
		_droped = _copyDroped(m);
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		return ;
	_count--;
	if (!_isInDroped(this->_inventory[idx]))
		_droped = _copyDroped(this->_inventory[idx]);
	this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3 || !this->_inventory[idx])
		return ;
	this->_inventory[idx]->use(target);
}

AMateria **Character::_copyDroped(AMateria *m)
{
	static AMateria *hold;

	if (m != hold)
	{
		hold = m;
		_droped_count++;
		AMateria **tmp = new AMateria*[_droped_count];
		for (int i = 0; i < _droped_count - 1; i++)
			tmp[i] = _droped[i];
		tmp[_droped_count - 1] = m;
		if (_droped)
			delete [] _droped;
		return (tmp);
	}
	else
		return (_droped);
}

bool Character::_isInDroped(AMateria *m)
{
	for (int i = 0; i < _droped_count; i++)
	{
		if (_droped[i] == m)
			return (true);
	}
	return (false);
}
