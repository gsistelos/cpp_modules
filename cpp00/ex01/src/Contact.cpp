#include "Contact.hpp"

void input( std::string const& output, std::string& buffer );
std::string shrink( std::string const& str );

Contact::Contact( void ) {
}

Contact::Contact( int index ) {
	this->_id = index + 1;
	input("First name: ", this->_first_name);
	input("Last name: ", this->_last_name);
	input("Nickname: ", this->_nickname);
	input("Darkest secret: ", this->_darkest_secret);
}

void Contact::info( void ) {
	std::cout << std::right << std::setw(10) << this->_id << " | ";
	std::cout << std::right << std::setw(10) << shrink(this->_first_name) << " | ";
	std::cout << std::right << std::setw(10) << shrink(this->_last_name) << " | ";
	std::cout << std::right << std::setw(10) << shrink(this->_nickname) << std::endl;
}

void Contact::details( void  ) {
	std::cout << std::endl;
	std::cout << "Index: " << this->_id << std::endl;
	std::cout << "First name: " << this->_first_name << std::endl;
	std::cout << "Last name: " << this->_last_name << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Darkest secret: " << this->_darkest_secret << std::endl;
	std::cout << std::endl;
}
