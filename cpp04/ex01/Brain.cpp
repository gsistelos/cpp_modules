#include "Brain.hpp"
#include <cstdlib>
#include <sys/time.h>

Brain::Brain(void)
{
	for (int i = 0; i < 25; i++) {
		ideas[i] = "I want water";
	}
	for (int i = 25; i < 50; i++) {
		ideas[i] = "I want food";
	}
	for (int i = 50; i < 75; i++) {
		ideas[i] = "I want to pee";
	}
	for (int i = 75; i < 100; i++) {
		ideas[i] = "I want to poop";
	}
	std::cout << "Brain: Default constructor called." << std::endl;
}

Brain::Brain(const Brain &other)
{
	for (int i = 0; i < 100; i++) {
		ideas[i] = other.ideas[i];
	}
	std::cout << "Brain: Copy constructor called." << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain: Destructor called." << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
	for (int i = 0; i < 100; i++) {
		ideas[i] = other.ideas[i];
	}
	std::cout << "Brain: Assignment constructor called." << std::endl;
	return *this;
}

std::string Brain::randomIdea(void) const
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	srand(tv.tv_usec);
	return ideas[rand() % 100];
}
