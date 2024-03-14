#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>

class ScalarConverter
{
private:
	enum Type { CHAR, INT, FLOAT, DOUBLE, INVALID };

	ScalarConverter( void );
	ScalarConverter( ScalarConverter const & other );

	~ScalarConverter();

	ScalarConverter& operator=( ScalarConverter const & other );

	static void (*functions[])( void );
	static std::string _literal;

	static Type getType( void );
	static bool validateLiteral( void );
	static size_t getPrecision( void );
	static void fromChar( void );
	static void fromInt( void );
	static void fromFloat( void );
	static void fromDouble( void );
	static void fromInvalid( void );

public:
	static void convert( std::string const & literal );
};

#endif /* SCALAR_CONVERTER_HPP */
