#include "ScalarConverter.hpp"
#include <stdlib.h>
#include <limits>
#include <iostream>
#include <iomanip>

void (*ScalarConverter::functions[])( void ) = {
	&ScalarConverter::fromChar, &ScalarConverter::fromInt,
	&ScalarConverter::fromFloat, &ScalarConverter::fromDouble,
	&ScalarConverter::fromInvalid
};

std::string ScalarConverter::_literal;

ScalarConverter::ScalarConverter( void )
{
}

ScalarConverter::ScalarConverter( ScalarConverter const & other )
{
	(void)other;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter& ScalarConverter::operator=( ScalarConverter const & other )
{
	(void)other;
	return *this;
}

ScalarConverter::Type ScalarConverter::getType( void )
{
	if (_literal.length() == 1 && std::isdigit(_literal[0]) == false)
		return CHAR;

	if (_literal == "nanf" || _literal == "+inff" || _literal == "-inff")
		return FLOAT;
	if (_literal == "nan" || _literal == "+inf" || _literal == "-inf")
		return DOUBLE;

	if (ScalarConverter::validateLiteral())
		return INVALID;

	if (_literal[_literal.length() - 1] == 'f')
		return FLOAT;
	if (_literal.find('.') != std::string::npos)
		return DOUBLE;

	return INT;
}

bool ScalarConverter::validateLiteral( void )
{
	size_t i = 0;

	if (_literal[i] == '+' || _literal[i] == '-')
		i++;

	size_t dots = 0;
	while (_literal[i]) {
		if (std::isdigit(_literal[i]) == false) {
			if (_literal[i] == '.' && dots == 0)
				dots++;
			else if (_literal[i] == 'f' && _literal[i + 1] == '\0')
				return 0;
			else
				return 1;
		}
		i++;
	}

	return 0;
}

size_t ScalarConverter::getPrecision( void )
{
	size_t offset = _literal.find('.');
	if (offset == std::string::npos)
		return 1;

	size_t precision = 0;

	for (size_t i = offset; _literal[i]; i++) {
		if (_literal[i] == 'f')
			break;
		else if (_literal[i] != '0')
			precision = i - offset;
	}

	if (precision == 0)
		precision = 1;

	return precision;
}

void ScalarConverter::fromChar( void )
{
	char c = _literal[0];

	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

void ScalarConverter::fromInt( void )
{
	int i = atoi(_literal.c_str());
	char c = static_cast<char>(i);

	if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max())
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(i) << std::endl;
}

void ScalarConverter::fromFloat( void )
{
	float f = static_cast<float>(atof(_literal.c_str()));
	char c = static_cast<char>(f);
	size_t precision = getPrecision();

	if (f < std::numeric_limits<char>::min() || f > std::numeric_limits<char>::max())
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (f < std::numeric_limits<int>::min() || f > (float)std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(precision) << f << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(precision) << static_cast<double>(f) << std::endl;
}

void ScalarConverter::fromDouble( void )
{
	double d = atof(_literal.c_str());
	char c = static_cast<char>(d);
	size_t precision = getPrecision();

	if (d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max())
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	if (d < std::numeric_limits<float>::min() || d > std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(precision) << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(precision) << d << std::endl;
}

void ScalarConverter::fromInvalid( void )
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

void ScalarConverter::convert( std::string const & literal )
{
	ScalarConverter::_literal = literal;

	Type type = getType();

	functions[type]();
}
