#include "Dog.hpp"
#include <iostream>

Dog::Dog( void ) : Animal("Dog"), brain(new Brain())
{
	std::cout << "Dog: Default constructor called" << std::endl;
}

Dog::Dog( Dog const & other ) : Animal(other.type), brain(new Brain(*other.brain))
{
	std::cout << "Dog: Copy constructor called" << std::endl;
}

Dog::~Dog()
{
	delete brain;

	std::cout << "Dog: Destructor called" << std::endl;
}

Dog& Dog::operator=( Dog const & other )
{
	Animal::operator=(other);

	delete brain;

	brain = new Brain(*other.brain);

	std::cout << "Dog: Assignment operator called" << std::endl;

	return *this;
}

void Dog::makeSound( void ) const
{
	std::cout << "Dog bark sound!" << std::endl;
}
