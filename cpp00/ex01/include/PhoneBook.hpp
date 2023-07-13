#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>

class PhoneBook
{
private:
	static const size_t _size = 8;
	size_t _index;
	Contact _contacts[_size];

	void add( void );
	void search( void );

	static void prompt( std::string& input );
public:
	PhoneBook( void );
	~PhoneBook();

	void start( void );
};

#endif /* PHONEBOOK_HPP */
