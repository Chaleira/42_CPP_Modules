#ifndef Serializer_HPP
# define Serializer_HPP

# include <iostream>
# include <stdint.h>
# include <string>
# include <exception>

typedef struct s_data
{
	int n;
} Data;

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &copy);
		Serializer &operator=(const Serializer &copy);
		~Serializer();

	public:
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
};

#endif
