#include "Bureaucrat.hpp"
#include <iostream>

int main( void )
{
	try {
		Bureaucrat random_guy("Random", 11);

		std::cout << random_guy << std::endl;
		random_guy.incrementGrade(10);
		std::cout << random_guy << std::endl;
	} catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Bureaucrat other_guy("Other", 150);

		std::cout << other_guy << std::endl;
		other_guy.incrementGrade(150);
		std::cout << other_guy << std::endl;
	} catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Bureaucrat other_guy("Other", 140);

		std::cout << other_guy << std::endl;
		other_guy.decrementGrade(11);
		std::cout << other_guy << std::endl;
	} catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Bureaucrat other_guy("Other", 151);

		std::cout << other_guy << std::endl;
		other_guy.incrementGrade(150);
		std::cout << other_guy << std::endl;
	} catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
