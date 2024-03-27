#include "RPN.hpp"
#include <iostream>

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Usage: ./rpn \"expression\"" << std::endl;
        return 1;
    }
    RPN::calculate(av[1]);
    return 0;
}