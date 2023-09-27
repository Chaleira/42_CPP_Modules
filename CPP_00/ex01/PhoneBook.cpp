#include <PhoneBook.hpp>

PhoneBook::PhoneBook()
{
	std::cout << "PhoneBook has been created!" << std::endl;
	num_contact = 0;
}

PhoneBook::~PhoneBook()
{
	std::cout << "PhoneBook has been destroyed!" << std::endl;
}

void PhoneBook::add_contact()
{
	int i = 0;
	while (i <= 7 && contact[i].get_filled() == true)
		i++;
	if (num_contact >= 8)
		i = num_contact % 8;
    contact[i].set_first_name();
	contact[i].set_last_name();
    contact[i].set_phone_number();
	contact[i].set_nickname();
	contact[i].set_darkest_secret();
	contact[i].set_filled(true);
	num_contact++;
}

void PhoneBook::print_table()
{
	int i = 0;
	std::cout << std::setw(10) << std::right << "Index" << " | "
              << std::setw(10) << std::right << "First Name" << " | "
              << std::setw(10) << std::right << "Last Name" << " | "
              << std::setw(10) << std::right << "Nickname" << std::endl;
	while (contact[i].get_filled() == true)
	{
		std::cout << std::setw(10) << std::right << (i + 1) << " | "
              << std::setw(10) << std::right << search_first_name(i) << " | "
              << std::setw(10) << std::right << search_last_name(i) << " | "
              << std::setw(10) << std::right << search_nickname(i) << std::endl;
		i++;
	}
}

void PhoneBook::search()
{
	print_table();
	int contact_index = 0;
	std::string index;
	std::cout << "Enter the index of the contact you want to search: ";
	std::getline(std::cin, index);
	if (index.empty())
		return;
	contact_index = std::atoi(index.c_str()) - 1;
	if (contact_index <= 7 && contact_index >= 0  && contact[contact_index].get_filled() == true)
		print_contact(contact_index);
	else
		std::cout << "Contact not found!" << std::endl;
}

std::string PhoneBook::search_first_name(int i)
{
	if (contact[i].get_first_name().length() > 10)
		return contact[i].get_first_name().substr(0, 9) + '.';
	return contact[i].get_first_name();
}

std::string PhoneBook::search_last_name(int i)
{
	if (contact[i].get_last_name().length() > 10)
		return contact[i].get_last_name().substr(0, 9) + '.';
	return contact[i].get_last_name();
}

std::string PhoneBook::search_nickname(int i)
{
	if (contact[i].get_nickname().length() > 10)
        return contact[i].get_nickname().substr(0, 9) + '.';
	return contact[i].get_nickname();
}

void PhoneBook::print_contact(int i)
{
	std::cout << "First name: " << contact[i].get_first_name() << std::endl;
	std::cout << "Last name: " << contact[i].get_last_name() << std::endl;
	std::cout << "Phone number: " << contact[i].get_phone_number() << std::endl;
	std::cout << "Nickname: " << contact[i].get_nickname() << std::endl;
	std::cout << "Darkest secret: " << contact[i].get_darkest_secret() << std::endl;
}