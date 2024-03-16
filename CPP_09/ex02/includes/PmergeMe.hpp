#ifndef PmergeMe_HPP
# define PmergeMe_HPP

# include <iostream>
# include <string>
# include <exception>

class PmergeMe
{
	private:

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &copy);
		PmergeMe &operator=(const PmergeMe &copy);
		~PmergeMe();
};

#endif
