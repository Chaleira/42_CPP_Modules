#include "PmergeMe.hpp"
#include <iostream>

int main(int ac, char **av)
{
	std::list<int> list;
	std::vector<int> vector;
	std::clock_t vector_start, vector_end, list_start, list_end;
	double vector_time, list_time;
	int a;
	char c;

	for (int i = 1; i < ac; ++i) {
		if (sscanf(av[i], "%d%c", &a, &c) == 1)
		{
			list.push_back(a);
			vector.push_back(a);
		}
		else
		{
			std::cerr << "Error: invalid argument" << std::endl;
			return 1;
		}
	}
	list_start = std::clock();
	PmergeMe::sort(list);
	list_end = std::clock();
	list_time = (double)(list_end - list_start) / CLOCKS_PER_SEC;
	std::cout << "Before sorting:" << std::endl;
	PmergeMe::print(vector);
	vector_start = std::clock();
	PmergeMe::sort(vector);
	vector_end = std::clock();
	std::cout << "After sorting:" << std::endl;
	PmergeMe::print(vector);
	vector_time = (double)(vector_end - vector_start) / CLOCKS_PER_SEC;
	std::cout << "list time:   " << std::fixed << list_time << " ms" << std::endl;
	std::cout << "vector time: " << std::fixed << vector_time << " ms" << std::endl;
	return 0;
}
