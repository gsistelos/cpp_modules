#include "Brain.hpp"
#include <iostream>

Brain::Brain( void )
{
	for (size_t i = 0; i < 25; i++) {
		ideas[i] = "I want water";
	}
	for (size_t i = 25; i < 50; i++) {
		ideas[i] = "I want food";
	}
	for (size_t i = 50; i < 75; i++) {
		ideas[i] = "I want to pee";
	}
	for (size_t i = 75; i < 100; i++) {
		ideas[i] = "I want to poop";
	}

	std::cout << "Brain: Default constructor called" << std::endl;
}

Brain::Brain( Brain const & other )
{
	for (size_t i = 0; i < 100; i++) {
		ideas[i] = other.ideas[i];
	}

	std::cout << "Brain: Copy constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain: Destructor called" << std::endl;
}

Brain &Brain::operator=( Brain const & other )
{
	for (size_t i = 0; i < 100; i++) {
		ideas[i] = other.ideas[i];
	}

	std::cout << "Brain: Assignment constructor called" << std::endl;

	return *this;
}
