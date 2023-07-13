#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
private:
	int _value;
	static int const _fractional_bits = 8;
public:
	Fixed( void );
	Fixed( Fixed const & other );
	~Fixed();

	Fixed& operator=( Fixed const & other );

	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif /* FIXED_HPP */
