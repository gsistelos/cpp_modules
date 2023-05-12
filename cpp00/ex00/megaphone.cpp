#include <iostream>

static void str_toupper( char* str )
{
	for (int i = 0; str[i]; i++) {
		str[i] = std::toupper(str[i]);
	}
}

int main( int argc, char** argv )
{
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}

	for (int i = 1; i < argc; i++) {
		str_toupper(argv[i]);
		std::cout << argv[i];
	}
	std::cout << std::endl;
	return 0;
}
