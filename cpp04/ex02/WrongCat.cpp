#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAAnimal("WrongCat")
{
	std::cout << "WrongCat: Default constructor called." << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAAnimal(other.type)
{
	std::cout << "WrongCat: Copy constructor called." << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat: Destructor called." << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	WrongAAnimal::operator=(other);
	std::cout << "WrongCat: Assignment operator called." << std::endl;
	return *this;
}

void WrongCat::makeSound(void) const
{
	std::cout << "WrongCat meow sound!" << std::endl;
}
