#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _size(0), _index(0)
{
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::add(void)
{
	Contact contact = _index;
	_contacts[this->_index] = contact;
	if (_size < SIZE)
		_size++;
	_index++;
	if (_index > 7)
		_index = 0;
	std::cout << "Added new contact" << std::endl;
}

void PhoneBook::search(void)
{
	std::cout << std::setw(10) << "Index" << " | ";
	std::cout << std::setw(10) << "First Name" << " | ";
	std::cout << std::setw(10) << "Last Name" << " | ";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < _size; i++) {
		_contacts[i].info();
	}
	std::cout << std::endl;

	std::cout << "Type the index you want to access: ";
	std::string sindex;
	std::getline(std::cin, sindex);
	if (sindex.length() != 1 || sindex.at(0) < '0' || sindex.at(0) > '7') {
		std::cout << "Invalid input" << std::endl;
		return ;
	}
	int index = std::atoi(sindex.c_str());
	if (index < 0 || index >= _size) {
		std::cout << "Invalid index" << std::endl;
		return ;
	}
	_contacts[index].details();
}
