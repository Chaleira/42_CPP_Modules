#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	std::cout << "PmergeMe constructor called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
	std::cout << "PmergeMe copy constructor called" << std::endl;
	// Don't forget to copy the variables
	*this = copy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
	(void)copy;
	std::cout << "PmergeMe operator= called" << std::endl;
	// Don't forget to copy the variables here
	return *this;
}

PmergeMe::~PmergeMe()
{
	std::cout << "PmergeMe destructor called" << std::endl;
}

void PmergeMe::print(std::vector<int> &vector)
{
	for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "-----------------" << std::endl;
	std::cout << std::endl;
}

void PmergeMe::print(std::list<int> &list)
{
	for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "-----------------" << std::endl;
	std::cout << std::endl;
}

std::list<int>::iterator get_list_index(std::list<int> &list, int value)
{
	std::list<int>::iterator it = list.begin();
	while (it != list.end() && *it < value)
		++it;
	return (it);
}

std::list<int>::iterator get_list_value(std::list<int> &list, int position)
{
	std::list<int>::iterator it = list.begin();
	std::advance(it, position);
	return (it);
}

const int PmergeMe::jacobsthal[35] = {
	-1, 0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923,
	21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203, 5592405,
	11184811, 22369621, 44739243, 89478485, 178956971, 357913941, 715827883,
	1431655765
};

void PmergeMe::insert_list(std::list<int> &list, std::list<int> &small)
{
	int jal_index = 0;
	while (jacobsthal[jal_index] < (int)small.size())
	{
		++jal_index;
		int position = (jacobsthal[jal_index] < (int)small.size()) ? jacobsthal[jal_index] : small.size() - 1;
		while (jacobsthal[jal_index - 1] < position)
		{
			std::list<int>::iterator small_it = get_list_value(small, position);
			if (small_it != small.end())
				list.insert(get_list_index(list, *small_it), *small_it);
			position--;
		}
	}
}

void PmergeMe::sort(std::list<int> &list)
{
	if (list.size() < 2)
		return;
	std::list<int> lower_list;
	std::list<int>::iterator first = list.begin();
	std::list<int>::iterator second = list.begin();
	std::advance(second, 1);
	std::list<int>::iterator temp;
	while (second != list.end() && first != list.end())
	{
		temp = *first < *second ? first : second;
		std::advance(first, 2);
		std::advance(second, 2);
		lower_list.splice(lower_list.end(), list, temp);
	}
	sort(list);
	insert_list(list, lower_list);
}

void PmergeMe::insert_vector(std::vector<int> &vector, std::vector<int> &small)
{
	int jal_index = 0;
	while (jacobsthal[jal_index] < (int)small.size())
	{
		++jal_index;
		int position = (jacobsthal[jal_index] < (int)small.size()) ? jacobsthal[jal_index] : small.size() - 1;
		while (jacobsthal[jal_index - 1] < position)
		{
			std::vector<int>::iterator small_it = small.begin() + position;
			if (small_it != small.end())
				vector.insert(std::lower_bound(vector.begin(), vector.end(), *small_it), *small_it);
			position--;
		}
	}
}

void PmergeMe::sort(std::vector<int> &vector)
{
	if (vector.size() < 2)
		return;
	std::vector<int> lower_vector;
	int first = 0, second = 1;
	while (second < (int)vector.size())
	{
		int temp = vector[first] < vector[second] ? first : second;
		first += 1;
		second += 1;
		lower_vector.push_back(vector[temp]);
		vector.erase(vector.begin() + temp);
	}
	sort(vector);
	insert_vector(vector, lower_vector);
}