#include "Contact.hpp"
#include <iostream>
#include <iomanip>

Contact::Contact( void ) : _first_name(""), _last_name(""), _nickname(""), _phone_number(""), _darkest_secret("")
{
}

Contact::~Contact()
{
}

void Contact::input( std::string const & output, std::string& buffer )
{
	std::cout << output;
	std::getline(std::cin, buffer);
	while (!std::cin.eof() && buffer.empty()) {
		std::cout << "Invalid input: empty line" << std::endl;
		std::cout << output;
		std::getline(std::cin, buffer);
	}
}

std::string Contact::shrink( std::string const & str )
{
	std::string sub = str.substr(0, 10);
	if (sub.length() == 10)
		sub[9] = '.';
	return sub;
}

void Contact::edit( void )
{
	input("First name: ", _first_name);
	input("Last name: ", _last_name);
	input("Nickname: ", _nickname);
	input("Phone Number: ", _phone_number);
	input("Darkest secret: ", _darkest_secret);
}

void Contact::info( void )
{
	std::cout << std::right << std::setw(10) << shrink(_first_name) << " | ";
	std::cout << std::right << std::setw(10) << shrink(_last_name) << " | ";
	std::cout << std::right << std::setw(10) << shrink(_nickname);
}

void Contact::details( void )
{
	std::cout << "First name: " << _first_name << std::endl;
	std::cout << "Last name: " << _last_name << std::endl;
	std::cout << "Nickname: " << _nickname << std::endl;
	std::cout << "Phone Number: " << _phone_number << std::endl;
	std::cout << "Darkest secret: " << _darkest_secret << std::endl;
}
