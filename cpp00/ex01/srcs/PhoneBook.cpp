#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>

PhoneBook::PhoneBook( void ) : _index(0)
{
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::start( void )
{
	std::string input;

	while (!std::cin.eof()) {
		prompt(input);
		if (input == "ADD")
			add();
		else if (input == "SEARCH")
			search();
		else if (input == "EXIT")
			break ;
		else
			std::cout << "Invalid action" << std::endl;
	}
}

void PhoneBook::prompt( std::string& input )
{
	std::cout << "|  ADD |  SEARCH  | EXIT  |" << std::endl;
	std::cout << ">";
	std::getline(std::cin, input);
}

void PhoneBook::add( void )
{
	_contacts[_index % _size].edit();
	_index++;
	std::cout << "Added new contact" << std::endl;
}

void PhoneBook::search( void )
{
	std::cout << std::setw(10) << "Index" << " | ";
	std::cout << std::setw(10) << "First Name" << " | ";
	std::cout << std::setw(10) << "Last Name" << " | ";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	for (size_t i = 0; i < _size; i++) {
		std::cout << std::right << std::setw(10) << i << " | ";
		_contacts[i].info();
		std::cout << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Type the index you want to access: ";
	std::string index;
	std::getline(std::cin, index);
	if (index.length() != 1 || index.at(0) < '0' || index.at(0) > '7') {
		std::cout << "Invalid input" << std::endl;
		return ;
	}

	std::cout << std::endl;
	std::cout << "Index: " << index << std::endl;
	_contacts[index.at(0) - '0'].details();
	std::cout << std::endl;
}
