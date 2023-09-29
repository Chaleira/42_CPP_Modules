#include "Harl.hpp"

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		std::cout << "Usage: <complain>" << std::endl;
		return 1;
	}
	Harl harl;
    harl.complain(std::string(argv[1]));
	return 0;
}
