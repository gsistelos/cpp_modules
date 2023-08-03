#include "Cat.hpp"
#include <iostream>

Cat::Cat( void ) : Animal("Cat")
{
	std::cout << "Cat: Default constructor called" << std::endl;
}

Cat::Cat( Cat const & other ) : Animal(other.type)
{
	std::cout << "Cat: Copy constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat: Destructor called" << std::endl;
}

Cat& Cat::operator=( Cat const & other )
{
	Animal::operator=(other);

	std::cout << "Cat: Assignment operator called" << std::endl;

	return *this;
}

void Cat::makeSound( void ) const
{
	std::cout << "Cat meow sound!" << std::endl;
}
