#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
	int _value;
	static const int _fractional_bits = 8;
public:
	Fixed( void );
	Fixed( int const value );
	Fixed( float const value );
	Fixed( Fixed const& other );
	~Fixed( void );
	Fixed& operator=( Fixed const& other );
	bool operator>( Fixed const& other ) const;
	bool operator<( Fixed const& other ) const;
	bool operator>=( Fixed const& other ) const;
	bool operator<=( Fixed const& other ) const;
	bool operator==( Fixed const& other ) const;
	bool operator!=( Fixed const& other ) const;
	Fixed& operator++( void );
	Fixed operator++( int );
	Fixed& operator--( void );
	Fixed operator--( int );
	Fixed operator+( Fixed const& other );
	Fixed operator-( Fixed const& other );
	Fixed operator*( Fixed const& other );
	Fixed operator/( Fixed const& other );
	friend std::ostream& operator<<( std::ostream& os, Fixed const& fixed );
	int toInt( void ) const;
	float toFloat( void ) const;
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	static Fixed& min( Fixed& fixed1, Fixed& fixed2 );
	static Fixed const& min( Fixed const& fixed1, Fixed const& fixed2 );
	static Fixed& max( Fixed& fixed1, Fixed& fixed2 );
	static Fixed const& max( Fixed const& fixed1, Fixed const& fixed2 );
};

#endif //FIXED_HPP
