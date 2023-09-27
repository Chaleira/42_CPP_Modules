#include <Contact.hpp>

Contact::Contact()
{
	std::cout << "Contact has been created!" << std::endl;
	this->filled = false;
}

Contact::~Contact()
{
	std::cout << "Contact has been destroyed!" << std::endl;
}

bool Contact::get_filled()
{
	return filled;
}

void Contact::set_filled(bool filled) {this->filled = filled;}

std::string Contact::get_first_name()
{
	return this->first_name;
}

std::string Contact::get_last_name()
{
	return this->last_name;
}

std::string Contact::get_phone_number()
{
	return this->phone_number;
}

std::string Contact::get_nickname()
{
	return this->nickname;
}

std::string Contact::get_darkest_secret()
{
    return this->darkest_secret;
}

void Contact::set_first_name()
{
	prompt:
	std::string first_name;
	first_name.clear();
	std::cout << "Enter your first name: ";
    std::getline(std::cin, first_name);
	if (first_name.empty())
        goto prompt;
    this->first_name = first_name;
}

void Contact::set_last_name()
{
	std::string last_name;
	prompt:
	std::cout << "Enter your last name: ";
	std::getline(std::cin, last_name);
	if (last_name.empty())
		goto prompt;
	this->last_name = last_name;
}

void Contact::set_phone_number()

{
	std::string phone_number;
	prompt:
    std::cout << "Enter your phone number: ";
    std::getline(std::cin, phone_number);
	if (phone_number.empty() || !isNumber(phone_number))
        goto prompt;
	this->phone_number = phone_number;
}

void Contact::set_nickname()
{
	std::string nickname;
	prompt:
    std::cout << "Enter your nickname: ";
	std::getline(std::cin, nickname);
	if (nickname.empty())
        goto prompt;
	this->nickname = nickname;
}

void Contact::set_darkest_secret()
{
	std::string darkest_secret;
	prompt:
    std::cout << "Enter your darkest secret: ";
	std::getline(std::cin, darkest_secret);
	if (darkest_secret.empty())
        goto prompt;
	this->darkest_secret = darkest_secret;
}

void Contact::set_contact(int contact)
{
	this->contact = contact;
}

int Contact::get_contact()
{
	return this->contact;
}

bool Contact::isNumber(const std::string s)
{
	for(std::string::const_iterator it = s.begin(); it != s.end(); it++)
		if (!std::isdigit(*it) && (*it != '+' && it == s.begin()) )
			return false;
	return true;
}