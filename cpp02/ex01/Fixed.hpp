#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>

class Fixed
{
private:
	int _value;
	static int const _fractional_bits = 8;
public:
	Fixed( void );
	Fixed( int value );
	Fixed( float value );
	Fixed( Fixed const & other );
	~Fixed();

	Fixed& operator=( Fixed const & other );

	int toInt( void ) const;
	float toFloat( void ) const;

	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

std::ostream& operator<<( std::ostream& os, Fixed const & fixed );

#endif /* FIXED_HPP */
