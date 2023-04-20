#include "Contact.hpp"

void input(std::string const &output, std::string &buffer);
std::string shrink(std::string const &str);

Contact::Contact(void)
{
}

Contact::Contact(int index)
{
	this->_index = index;
	input("First name: ", _first_name);
	input("Last name: ", _last_name);
	input("Nickname: ", _nickname);
	input("Phone Number: ", _phone_number);
	input("Darkest secret: ", _darkest_secret);
}

Contact::~Contact()
{
}

void Contact::info(void)
{
	std::cout << std::right << std::setw(10) << _index << " | ";
	std::cout << std::right << std::setw(10) << shrink(_first_name) << " | ";
	std::cout << std::right << std::setw(10) << shrink(_last_name) << " | ";
	std::cout << std::right << std::setw(10) << shrink(_nickname) << std::endl;
}

void Contact::details(void)
{
	std::cout << std::endl;
	std::cout << "Index: " << _index << std::endl;
	std::cout << "First name: " << _first_name << std::endl;
	std::cout << "Last name: " << _last_name << std::endl;
	std::cout << "Nickname: " << _nickname << std::endl;
	std::cout << "Phone Number: " << _phone_number << std::endl;
	std::cout << "Darkest secret: " << _darkest_secret << std::endl;
	std::cout << std::endl;
}
