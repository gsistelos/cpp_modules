#include "Bureaucrat.hpp"
#include <iostream>

int main( void )
{
	try {
		Bureaucrat random_guy("Random", 1);

		std::cout << random_guy << std::endl;
		random_guy.incrementGrade();
		std::cout << random_guy << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Bureaucrat other_guy("Other", 150);

		std::cout << other_guy << std::endl;
		other_guy.decrementGrade();
		std::cout << other_guy << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Bureaucrat other_guy("Other", -10);

		std::cout << other_guy << std::endl;
		other_guy.decrementGrade();
		std::cout << other_guy << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Bureaucrat other_guy("Other", 1);

		std::cout << other_guy << std::endl;
		other_guy.decrementGrade();
		std::cout << other_guy << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
