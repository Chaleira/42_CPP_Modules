#pragma once

#include <algorithm>
#include <iostream>

class NotFoundException : public std::exception
{
public:
	virtual const char *what() const throw()
	{
		return "Value not found";
	}
};

template <typename T>
int easyfind(T &container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw NotFoundException();
	return *it;
}
