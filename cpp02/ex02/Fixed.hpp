#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

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

	bool operator>( Fixed const & other ) const;
	bool operator<( Fixed const & other ) const;
	bool operator>=( Fixed const & other ) const;
	bool operator<=( Fixed const & other ) const;
	bool operator==( Fixed const & other ) const;
	bool operator!=( Fixed const & other ) const;

	Fixed operator+( Fixed const & other );
	Fixed operator-( Fixed const & other );
	Fixed operator*( Fixed const & other );
	Fixed operator/( Fixed const & other );

	Fixed& operator++( void );
	Fixed operator++( int );
	Fixed& operator--( void );
	Fixed operator--( int );

	static Fixed& min( Fixed& a, Fixed& b );
	static Fixed const & min( Fixed const & a, Fixed const & b );
	static Fixed& max( Fixed& a, Fixed& b );
	static Fixed const & max( Fixed const & a, Fixed const & b );

	int toInt( void ) const;
	float toFloat( void ) const;

	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

std::ostream& operator<<( std::ostream& os, Fixed const & fixed );

#endif /* FIXED_HPP */
