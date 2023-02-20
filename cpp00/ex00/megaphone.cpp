#include <iostream>

static void	str_upper(char *argv) {
	for (int i = 0; argv[i]; i++) {
		argv[i] = std::toupper(argv[i]);
	}
}

int	main(int argc, char **argv) {
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	for (int i = 1; i < argc; i++) {
		str_upper(argv[i]);
		std::cout << argv[i];
	}
	std::cout << std::endl;
	return (0);
}
