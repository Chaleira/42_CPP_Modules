#include "Harl.hpp"

int main(void)
{
	Harl harl;

	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("CRITICAL");
	harl.complain("ALERT");
	harl.complain("EMERGENCY");
	harl.complain("FATAL");
	std::cout << std::endl;
	// harl.complain("DEBUG");
	// harl.complain("INFO");
	// harl.complain("WARNING");
	// harl.complain("ERROR");
	return 0;
}
