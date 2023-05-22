#include "Fixed.hpp"

Fixed::Fixed( void ) : _value(0)
{
}

Fixed::Fixed( int const value ) : _value(value << _fractional_bits)
{
}

Fixed::Fixed( float const value ) : _value(value * (1 << _fractional_bits))
{
}

Fixed::Fixed( Fixed const & other )
{
	*this = other;
}

Fixed::~Fixed()
{
}

Fixed& Fixed::operator=( Fixed const & other )
{
	_value = other.getRawBits();
	return *this;
}

bool Fixed::operator>( Fixed const & other ) const
{
	return _value > other.getRawBits();
}

bool Fixed::operator<( Fixed const & other ) const
{
	return _value < other.getRawBits();
}

bool Fixed::operator>=( Fixed const & other ) const
{
	return _value >= other.getRawBits();
}

bool Fixed::operator<=( Fixed const & other ) const
{
	return _value >= other.getRawBits();
}

bool Fixed::operator==( Fixed const & other ) const
{
	return _value == other.getRawBits();
}

bool Fixed::operator!=( Fixed const & other ) const
{
	return _value != other.getRawBits();
}

Fixed Fixed::operator+( Fixed const & other )
{
	return Fixed(toFloat() + other.toFloat());
}

Fixed Fixed::operator-( Fixed const & other )
{
	return Fixed(toFloat() - other.toFloat());
}

Fixed Fixed::operator*( Fixed const & other )
{
	return Fixed(toFloat() * other.toFloat());
}

Fixed Fixed::operator/( Fixed const & other )
{
	return Fixed(toFloat() / other.toFloat());
}

Fixed& Fixed::operator++( void )
{
	++_value;
	return *this;
}

Fixed Fixed::operator++( int )
{
	Fixed tmp(*this);
	++*this;
	return tmp;
}

Fixed& Fixed::operator--( void )
{
	--_value;
	return *this;
}

Fixed Fixed::operator--( int )
{
	Fixed tmp(*this);
	--*this;
	return tmp;
}

Fixed& Fixed::min( Fixed& a, Fixed& b )
{
	if (a < b)
		return a;
	return b;
}

Fixed const & Fixed::min( Fixed const & a, Fixed const & b )
{
	if (a < b)
		return a;
	return b;
}

Fixed& Fixed::max( Fixed& a, Fixed& b )
{
	if (a > b)
		return a;
	return b;
}

Fixed const & Fixed::max( Fixed const & a, Fixed const & b )
{
	if (a > b)
		return a;
	return b;
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
