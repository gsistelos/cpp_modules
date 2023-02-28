#include "PhoneBook.hpp"

PhoneBook::PhoneBook( void ) : _size(0), _index(0) {
}

void PhoneBook::add( void ) {
	Contact contact = this->_index;
	this->_contacts[this->_index] = contact;
	if (this->_size < SIZE)
		this->_size++;
	this->_index++;
	this->_index %= SIZE;
	std::cout << "Added new contact" << std::endl;
}

void PhoneBook::search( void ) {
	std::cout << std::right << std::setw(10) << "Index" << " | ";
	std::cout << std::right << std::setw(10) << "First Name" << " | ";
	std::cout << std::right << std::setw(10) << "Last Name" << " | ";
	std::cout << std::right << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < this->_size; i++) {
		this->_contacts[i].info();
	}

	std::cout << "\nType the index you want to access: ";
	std::string sindex;
	std::getline(std::cin, sindex);
	if (sindex.length() != 1 || sindex.at(0) < '0' || sindex.at(0) > '7') {
		std::cout << "Invalid input" << std::endl;
		return ;
	}
	int index;
	std::istringstream(sindex) >> index;
	if (index < 0 || index >= this->_size) {
		std::cout << "Invalid index" << std::endl;
		return ;
	}
	for (int i = 0; i <= this->_size; i++) {
		if (index == i) {
			this->_contacts[i].details();
			return ;
		}
	}
}
