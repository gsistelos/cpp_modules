#include "Fixed.hpp"

Fixed::Fixed( void ) : _value(0) {
}

Fixed::Fixed( int const value ) : _value(value << this->_fractional_bits) {
}

Fixed::Fixed( float const value ) {
	this->_value = round(value * (1 << this->_fractional_bits));
}

Fixed::Fixed( Fixed const& other ) {
	*this = other;
}

Fixed::~Fixed( void ) {
}

Fixed& Fixed::operator=( Fixed const& other ) {
	this->_value = other.getRawBits();
	return *this;
}

bool Fixed::operator>( Fixed const& other ) const {
	return this->_value > other.getRawBits();
}

bool Fixed::operator<( Fixed const& other ) const {
	return this->_value < other.getRawBits();
}

bool Fixed::operator>=( Fixed const& other ) const {
	return this->_value >= other.getRawBits();
}

bool Fixed::operator<=( Fixed const& other ) const {
	return this->_value >= other.getRawBits();
}

bool Fixed::operator==( Fixed const& other ) const {
	return this->_value == other.getRawBits();
}

bool Fixed::operator!=( Fixed const& other ) const {
	return this->_value != other.getRawBits();
}

Fixed& Fixed::operator++( void ) {
	this->_value += 1;
	return *this;
}

Fixed Fixed::operator++( int ) {
	Fixed tmp = *this;
	++*this;
	return tmp;
}

Fixed& Fixed::operator--( void ) {
	this->_value -= 1;
	return *this;
}

Fixed Fixed::operator--( int ) {
	Fixed tmp = *this;
	--*this;
	return tmp;
}

Fixed Fixed::operator+( Fixed const& other ) {
	Fixed fixed;
	fixed.setRawBits(this->_value + other.getRawBits());
	return fixed;
}

Fixed Fixed::operator-( Fixed const& other ) {
	Fixed fixed;
	fixed.setRawBits(this->_value - other.getRawBits());
	return fixed;
}

Fixed Fixed::operator*( Fixed const& other ) {
    Fixed fixed;
    fixed.setRawBits((this->_value * other.getRawBits()) >> this->_fractional_bits);
    return fixed;
}

Fixed Fixed::operator/( Fixed const& other ) {
    Fixed fixed;
    fixed.setRawBits((this->_value / other.getRawBits()) >> this->_fractional_bits);
    return fixed;
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
	return this->_value;
}

void Fixed::setRawBits( int const raw ) {
	this->_value = raw;
}

Fixed& Fixed::min( Fixed& fixed1, Fixed& fixed2 ) {
	if (fixed1 < fixed2)
		return fixed1;
	return fixed2;
}

Fixed const& Fixed::min( Fixed const& fixed1, Fixed const& fixed2 ) {
	if (fixed1 < fixed2)
		return fixed1;
	return fixed2;
}

Fixed& Fixed::max( Fixed& fixed1, Fixed& fixed2 ) {
	if (fixed1 > fixed2)
		return fixed1;
	return fixed2;
}

Fixed const& Fixed::max( Fixed const& fixed1, Fixed const& fixed2 ) {
	if (fixed1 > fixed2)
		return fixed1;
	return fixed2;
}
