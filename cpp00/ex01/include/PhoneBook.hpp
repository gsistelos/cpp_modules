#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>

#define SIZE 8

class PhoneBook
{
private:
	int _size;
	int _index;
	Contact _contacts[SIZE];
public:
	PhoneBook(void);
	~PhoneBook();

	void add(void);
	void search(void);
};

#endif /* PHONEBOOK_HPP */
