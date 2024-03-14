#include "Span.hpp"

Span::Span(unsigned int n) : _max(INT_MIN), _min(INT_MAX)
{
	_arr.reserve(n);
}

Span::Span(const Span &copy)
{
	*this = copy;
}

Span &Span::operator=(const Span &copy)
{
	if (this == &copy)
		return *this;
	_arr.resize(copy._arr.size());
	_arr = copy._arr;
	_max = copy._max;
	_min = copy._min;
	return *this;
}

Span::~Span() {}

const char *Span::SpanFullException::what() const throw()
{
	return "Span is full";
}

const char *Span::InvalidSpanException::what() const throw()
{
	return "No span to find";
}

void Span::addNumber(int n)
{
	if (_arr.size() >= _arr.capacity())
		throw SpanFullException();
	n < _min ? _min = n : 0;
	n > _max ? _max = n : 0;
	_arr.push_back(n);
}

int Span::shortestSpan()
{
	if (_arr.size() < 2)
		throw InvalidSpanException();
	int min = INT_MAX;
	for (unsigned int i = 0; i < _arr.size(); i++)
	{
		for (unsigned int j = i + 1; j < _arr.size(); j++)
		{
			int diff = _arr[i] - _arr[j];
			if (diff < 0)
				diff = -diff;
			if (diff < min)
				min = diff;
		}
	}
	return min;
}

int Span::longestSpan()
{
	if (_arr.size() < 2)
		throw InvalidSpanException();
	return _max - _min;
}

void Span::SpanFill(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_arr.size() + std::distance(begin, end) > _arr.capacity())
		throw SpanFullException();
	for (std::vector<int>::iterator it = begin; it != end; it++)
	{
		*it < _min ? _min = *it : 0;
		*it > _max ? _max = *it : 0;
	
	}
	_arr.insert(_arr.end(), begin, end);
}
