#ifndef PmergeMe_HPP
# define PmergeMe_HPP

# include <iostream>
# include <string>
# include <exception>
# include <queue>
# include <vector>
# include <algorithm>
# include <sstream>
# include <list>
# include <climits>
# include <cmath>
# include <ctime>
# include <fstream>
# include <sstream>
# include <cstdlib>
# include <cstring>


class PmergeMe
{
	private:

		static const int jacobsthal[35];

		PmergeMe();
		PmergeMe(const PmergeMe &copy);
		PmergeMe &operator=(const PmergeMe &copy);
		~PmergeMe();

		static void insert_list(std::list<int> &list, std::list<int> &insert);
		static void insert_vector(std::vector<int> &vector, std::vector<int> &insert);


	public:
		static void sort(std::list<int> &list);
		static void sort(std::vector<int> &vector);
		static void print(std::vector<int> &vector);
		static void print(std::list<int> &list);

};

#endif
