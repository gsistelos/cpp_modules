#include "Animal.hpp"

Animal::Animal(void) : type("Animal")
{
	std::cout << "Animal: Default constructor called." << std::endl;
}

Animal::Animal(const std::string &type) : type(type)
{
	std::cout << "Animal: type constructor called." << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type)
{
	std::cout << "Animal: Copy constructor called." << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal: Destructor called." << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	type = other.type;
	std::cout << "Animal: Assignment operator called." << std::endl;
	return *this;
}

std::string Animal::getType(void) const
{
	return type;
}

void Animal::makeSound(void) const
{
	std::cout << "Animal sound!" << std::endl;
}
