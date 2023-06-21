#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
private:
	enum Type { CHAR, INT, FLOAT, DOUBLE, INVALID };

	typedef void (*func)(std::string const &);
	static func functions[];

	static Type getType( std::string const & literal );
	static bool isValidNumber( std::string const & literal );
	static void fromChar( std::string const & literal );
	static void fromInt( std::string const & literal );
	static void fromFloat( std::string const & literal );
	static void fromDouble( std::string const & literal );
	static void printConversions( char c, int i, float f, double d, int precision );
public:
	ScalarConverter( void );
	ScalarConverter( ScalarConverter const & other );

	~ScalarConverter();

	ScalarConverter& operator=( ScalarConverter const & other );

	static void convert( std::string const & literal );
};

#endif /* SCALARCONVERTER_HPP */
