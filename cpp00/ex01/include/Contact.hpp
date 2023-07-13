#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
private:
	std::string _first_name;
	std::string _last_name;
	std::string _nickname;
	std::string _phone_number;
	std::string _darkest_secret;

	static void input( std::string const & output, std::string& buffer );
	static std::string shrink( std::string const & str );
public:
	Contact( void );
	Contact( int index );
	~Contact();

	void edit( void );
	void info( void );
	void details( void );
};

#endif /* CONTACT_HPP */
