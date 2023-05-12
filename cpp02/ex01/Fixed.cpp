#include "Fixed.hpp"

Fixed::Fixed( void ) : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( int const value ) : _value(value << _fractional_bits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( float const value ) : _value(round(value * (1 << _fractional_bits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed( Fixed const & other )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=( Fixed const & other )
{
	std::cout << "Copy assignment operator called" << std::endl;
	_value = other.getRawBits();
	return *this;
}

int Fixed::toInt( void ) const
{
	return _value >> _fractional_bits;
}

float Fixed::toFloat( void ) const
{
	return (float)_value / (1 << _fractional_bits);
}

int Fixed::getRawBits( void ) const
{
	return _value;
}

void Fixed::setRawBits( int const raw )
{
	_value = raw;
}

std::ostream& operator<<( std::ostream& os, Fixed const & fixed )
{
	os << fixed.toFloat();
	return os;
}
