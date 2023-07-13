#include "Fixed.hpp"
#include <iostream>

int main( void )
{
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;

		std::cout << b << std::endl;

		std::cout << Fixed::max( a, b ) << std::endl;

	}
	std::cout << std::endl;
	{
		Fixed a(float(1.5));
	
		std::cout << a << std::endl;
		a = a + 10;
		std::cout << a << std::endl;
		a = a * float(2);
		std::cout << a << std::endl;
		a = a / 2;
		std::cout << a << std::endl;
		a = a - 4;
		std::cout << a << std::endl;
	}
	return 0;
}
