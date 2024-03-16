#include "BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char **av)
{
    (void)av;
    if (ac != 2)
    {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }
    try {
        BitcoinExchange exchange(av[1]);
        // exchange.PrintDataBase
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
