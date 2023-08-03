#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat( void ) : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat: Default constructor called" << std::endl;
}

WrongCat::WrongCat( WrongCat const & other ) : WrongAnimal(other.type)
{
	std::cout << "WrongCat: Copy constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat: Destructor called" << std::endl;
}

WrongCat& WrongCat::operator=( WrongCat const & other )
{
	WrongAnimal::operator=(other);

	std::cout << "WrongCat: Assignment operator called" << std::endl;

	return *this;
}

void WrongCat::makeSound( void ) const
{
	std::cout << "WrongCat meow sound!" << std::endl;
}
