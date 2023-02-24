#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact {
private:
	int _id;
	std::string _first_name;
	std::string _last_name;
	std::string _nickname;
	std::string _darkest_secret;
public:
	Contact( void );
	Contact( int index );
	void info( void );
	void details( void );
};

#endif //CONTACT_HPP
