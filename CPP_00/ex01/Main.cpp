#include <PhoneBook.hpp>

int main(void)
{
	std::string command;
	PhoneBook phoneBook;
	while (true)
	{
		std::cout << "Enter a command: ";
		std::getline(std::cin, command);
		if (command == "ADD")
			phoneBook.add_contact();
		if (command == "SEARCH")
			phoneBook.search();
		if (command == "EXIT")
			break;
	}
	return (0);
}
