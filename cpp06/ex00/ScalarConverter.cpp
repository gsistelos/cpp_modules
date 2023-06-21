#include "ScalarConverter.hpp"
#include <stdlib.h>
#include <math.h>
#include <limits>
#include <iostream>
#include <sstream>
#include <iomanip>

ScalarConverter::func ScalarConverter::functions[] = {
	&ScalarConverter::fromChar, &ScalarConverter::fromInt,
	&ScalarConverter::fromFloat, &ScalarConverter::fromDouble
};

ScalarConverter::ScalarConverter( void )
{
}

ScalarConverter::ScalarConverter( ScalarConverter const & other )
{
	*this = other;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter& ScalarConverter::operator=( ScalarConverter const & other )
{
	(void)other;
	return *this;
}

ScalarConverter::Type ScalarConverter::getType( std::string const & literal )
{
	if (literal.length() == 1 && !std::isdigit(literal.at(0)))
		return CHAR;

	if (literal == "nanf" || literal == "+inff" || literal == "-inff")
		return FLOAT;
	if (literal == "nan" || literal == "+inf" || literal == "-inf")
		return DOUBLE;
	
	if (ScalarConverter::isValidNumber(literal) == false)
		return INVALID;

	if (literal.find('f') != std::string::npos) {
		if (literal.find('.') != std::string::npos)
			return FLOAT;
		return INVALID;
	}
	if (literal.find('.') != std::string::npos) {
		return DOUBLE;
	}
	return INT;
}

bool ScalarConverter::isValidNumber( std::string const & literal )
{
	size_t i = 0;
	if (!std::isdigit(literal.at(i))) {
		if (literal.at(i) != '+' && literal.at(i) != '-')
			return false;
		i++;
		if (!std::isdigit(literal.at(i)))
			return false;
	}
	i++;

	size_t dots = 0;

	for (; i < literal.length() - 1; i++) {
		if (std::isdigit(literal.at(i)))
			continue ;
		if (literal.at(i) != '.')
			break ;
		dots++;
		if (dots > 1)
			return false;
	}
	if ((i == literal.length() - 1 && (std::isdigit(literal.at(i)) || literal.at(i) == 'f')))
		return true;
	return false;
}

void ScalarConverter::fromChar( std::string const & literal )
{
	std::cout << "char conversion" << std::endl;

	char c = literal.at(0);

	printConversions(c, static_cast<int>(c),
		static_cast<float>(c), static_cast<double>(c), 1);
}

void ScalarConverter::fromInt( std::string const & literal )
{
	std::cout << "int conversion" << std::endl;

	int i = std::atoi(literal.c_str());

	std::stringstream ss;
	ss << i;
	if (ss.str() != literal) {
		std::cerr << "Invalid conversion: overflow" << std::endl;
		std::cerr << "conversion: " << ss.str() << std::endl;
		return ;
	}

	printConversions(static_cast<char>(i), i,
		static_cast<float>(i), static_cast<double>(i), 1);
}

void ScalarConverter::fromFloat( std::string const & literal )
{
	std::cout << "float conversion" << std::endl;

	float f = std::atof(literal.c_str());

	int precision = literal.length() - literal.find('.') - 2;

	std::stringstream ss;
	ss << std::fixed << std::setprecision(precision) << f << "f";
	if (ss.str() != literal) {
		std::cerr << "Invalid conversion: overflow" << std::endl;
		std::cerr << "conversion: " << ss.str() <<std::endl;
		return ;
	}

	printConversions(static_cast<char>(f), static_cast<int>(f),
		f, static_cast<double>(f), precision);
}

void ScalarConverter::fromDouble( std::string const & literal )
{
	std::cout << "double conversion" << std::endl;

	double d = std::atof(literal.c_str());

	int precision = literal.length() - literal.find('.') - 1;

	std::stringstream ss;
	ss << std::fixed << std::setprecision(precision) << d;
	if (ss.str() != literal) {
		std::cerr << "Invalid conversion: overflow" << std::endl;
		std::cerr << "conversion: " << ss.str() <<std::endl;
		return ;
	}

	printConversions(static_cast<char>(d), static_cast<int>(d),
		static_cast<float>(d), d, precision);
}

void ScalarConverter::printConversions( char c, int i, float f, double d, int precision )
{
	if (floor(d) != c) {
		std::cout << "char: impossible" << std::endl;
	} else if (std::isprint(c)) {
		std::cout << "char: " << c << std::endl;
	} else {
		std::cout << "char: Non displayable" << std::endl;
	}

	if (floor(d) != i) {
		std::cout << "int: impossible" << std::endl;
	} else {
		std::cout << "int: " << i << std::endl;
	}

	if (d != f) { // comparision messing floating point values fsr
		std::cout << "float: impossible" << std::endl;
	} else {
		std::cout << std::fixed << std::setprecision(precision) << "float: " << f << "f" << std::endl;
	}

	std::cout << std::fixed << std::setprecision(precision) << "double: " << d << std::endl;
}

void ScalarConverter::convert( std::string const & literal )
{
	Type type = getType(literal);
	if (type == INVALID) {
		std::cerr << "Invalid conversion: invalid type" << std::endl;
		return ;
	}
	functions[type](literal);
}
