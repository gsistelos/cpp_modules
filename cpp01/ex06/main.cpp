#include "Harl.hpp"
#include <iostream>

int main( int argc, char** argv )
{
	Harl harl;

	if (argc != 2) {
		std::cout <<  "[ Probably complaining about insignificant problems ]" << std::endl;
		return 0;
	}

	harl.complain(argv[1]);
	return 0;
}
