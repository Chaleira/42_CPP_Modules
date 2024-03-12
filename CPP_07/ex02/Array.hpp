#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>
# include <cmath>


template <typename T>

class Array
{
	private:
		size_t _size;
		T *elements;

	public:
		Array() : elements(NULL), _size(0) {}

		Array(unsigned int n) : _size(n), elements(new T[n]) {}

		Array(Array const &other) {
			elements = new T[other.size()];
			_size = other.size();
			for (unsigned int i = 0; i < other.size(); i++) {
				elements[i] = other.elements[i];
			}
		}

		Array &operator=(Array const &other) {
			if (this != &other) {
				delete[] elements;
				elements = new T[other.size()];
				size = other.size();
				for (unsigned int i = 0; i < other.size(); i++) {
					elements[i] = other.elements[i];
				}
			}
			return *this;
		}

		T &operator[](int index) {
			if (index < 0 || static_cast<size_t>(index) >= size()) {
				throw OutOfRangeException();
			}
			return elements[index];
		}

		size_t size(void) const{
			return _size;
		}

		~Array() {
			delete[] elements;
		}

		class OutOfRangeException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return "Index out of range";
				}
		};
};

#endif