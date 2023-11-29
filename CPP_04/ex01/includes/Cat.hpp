#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *brain;
	public:
		Cat();
		Cat(const Cat &copy);
		Cat &operator=(const Cat &copy);
		~Cat();

		void makeSound() const;
		void setIdeas(std::string idea);
		void showIdeas() const;
};

#endif