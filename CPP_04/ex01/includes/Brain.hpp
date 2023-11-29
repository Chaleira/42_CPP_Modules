#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>


class Brain
{
	protected:
		std::string ideas[100];
	public:
		Brain();
		Brain(Brain const &other);
		~Brain();
		Brain &operator=(Brain const &other);

		std::string getIdeas() const;
		void setIdeas(std::string idea);
};

#endif