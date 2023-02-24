#include "Fixed.hpp"

Fixed::Fixed( void ) : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( int const value ) : _value(value << this->_fractional_bits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( float const value ) {
	std::cout << "Float constructor called" << std::endl;
	this->_value = round(value * (1 << this->_fractional_bits));
}

Fixed::Fixed( Fixed const& other ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=( Fixed const& other ) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = other._value;
	return *this;
}

std::ostream& operator<<( std::ostream& os, Fixed const& fixed ) {
	os << fixed.toFloat();
	return os;
}

int Fixed::toInt( void ) const {
	return this->_value >> this->_fractional_bits;
}

float Fixed::toFloat( void ) const {
	return (float)this->_value / (1 << this->_fractional_bits);
}

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}
