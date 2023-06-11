#include "Fixed.hpp"

/* __Constructors__ */

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

/* __Destructors__ */

Fixed::~Fixed()
{
}

/* __Comparison Operators__ */

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

/* __Arithmetic Operators__ */

Fixed Fixed::operator+( Fixed const & other )
{
	Fixed fixed;

	fixed.setRawBits(this->_value + other.getRawBits());
	return fixed;
}

Fixed Fixed::operator-( Fixed const & other )
{
	Fixed fixed;

	fixed.setRawBits(this->_value - other.getRawBits());
	return fixed;
}

Fixed Fixed::operator*( Fixed const & other )
{
	return toFloat() * other.toFloat();
}

Fixed Fixed::operator/( Fixed const & other )
{
	return toFloat() / other.toFloat();
}

/* __Pre-increment/decrement __ */

Fixed& Fixed::operator++( void )
{
	++_value;
	return *this;
}

Fixed& Fixed::operator--( void )
{
	--_value;
	return *this;
}

/* __Post-increment/decrement__ */

Fixed Fixed::operator++( int )
{
	Fixed tmp(*this);
	++*this;
	return tmp;
}

Fixed Fixed::operator--( int )
{
	Fixed tmp(*this);
	--*this;
	return tmp;
}

/* __Member Functions__ */

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

/* __Functions__ */

std::ostream& operator<<( std::ostream& os, Fixed const & fixed )
{
	os << fixed.toFloat();
	return os;
}
