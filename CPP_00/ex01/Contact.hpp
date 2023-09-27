#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
private:
	std::string first_name;
	std::string last_name;
	std::string phone_number;
	std::string nickname;
	std::string darkest_secret;
	int contact;
	bool filled;
	bool isNumber(const std::string s);

public:
	Contact();
	~Contact();
	void set_first_name();
	void set_last_name();
	void set_phone_number();
	void set_nickname();
	void set_darkest_secret();
	void set_filled(bool filled);
	void set_contact(int contact);
	bool get_filled();
	std::string get_first_name();
	std::string get_last_name();
	std::string get_phone_number();
	std::string get_nickname();
	std::string get_darkest_secret();
	int get_contact();
};

#endif