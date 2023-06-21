#include "ScalarConverter.hpp"
#include <iostream>

int main( int argc, char** argv )
{
	if (argc < 2) {
		std::cout << "usage: ./convert <literals>" << std::endl;
		return 1;
	}
	for (int i = 1; argv[i] != NULL; i++) {
		ScalarConverter::convert(argv[i]);
	}
	return 0;
}
