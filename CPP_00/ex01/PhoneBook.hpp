#ifndef PHONE_BOOOK_HPP
# define PHONE_BOOOK_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include <cstdlib>
# include <Contact.hpp>

class PhoneBook
{
private:
	Contact contact[8];
	int num_contact;
	std::string search_first_name(int i);
	std::string search_last_name(int i);
	std::string search_nickname(int i);
	void print_table(void);
	void print_contact(int i);
public:
	PhoneBook();
	~PhoneBook();
	void add_contact();
	void search();
};

#endif