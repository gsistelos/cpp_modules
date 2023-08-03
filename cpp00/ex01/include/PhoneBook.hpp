#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include "Contact.hpp"
#include <string>

#define SIZE 8

class PhoneBook
{
private:
	size_t _index;
	Contact _contacts[SIZE];

	void add( void );
	void search( void );

	static void prompt( std::string& input );

public:
	PhoneBook( void );
	~PhoneBook();

	void start( void );
};

#endif /* PHONE_BOOK_HPP */
