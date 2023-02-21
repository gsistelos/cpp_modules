#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _size(0), _index(0) {
}

void PhoneBook::add() {
	Contact contact = this->_index;
	this->_contacts[this->_index] = contact;
	if (this->_size < SIZE)
		this->_size++;
	this->_index++;
	this->_index %= SIZE;
	std::cout << "Added new contact" << std::endl;
}

void PhoneBook::search() {
	label();
	for (int i = 0; i < this->_size; i++) {
		this->_contacts[i].printContact();
	}
	std::string sindex;
	std::cout << "\nType the ID you want to access: ";
	std::getline(std::cin, sindex);
	int index;
	std::istringstream(sindex) >> index;
	if (index < 1 || index > this->_size) {
		std::cout << "Invalid ID" << std::endl;
		return ;
	}
	for (int i = 0; i < this->_size; i++) {
		if (index == i + 1)
			this->_contacts[i].printFullContact();
	}
}
