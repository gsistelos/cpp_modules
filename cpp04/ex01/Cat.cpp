#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat"), brain(new Brain())
{
	std::cout << "Cat: Default constructor called." << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other.type), brain(new Brain(*other.brain))
{
	std::cout << "Cat: Copy constructor called." << std::endl;
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat: Destructor called." << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	Animal::operator=(other);
	delete brain;
	brain = new Brain(*other.brain);
	std::cout << "Cat: Assignment operator called." << std::endl;
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "Cat meow sound!" << std::endl;
}
