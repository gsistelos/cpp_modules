#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal( void ) : type("WrongAnimal")
{
	std::cout << "WrongAnimal: Default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal( std::string const & type ) : type(type)
{
	std::cout << "WrongAnimal: type constructor called." << std::endl;
}

WrongAnimal::WrongAnimal( WrongAnimal const & other ) : type(other.type)
{
	std::cout << "WrongAnimal: Copy constructor called." << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal: Destructor called." << std::endl;
}

WrongAnimal& WrongAnimal::operator=( WrongAnimal const & other )
{
	type = other.type;
	std::cout << "WrongAnimal: Assignment operator called." << std::endl;
	return *this;
}

std::string WrongAnimal::getType( void ) const
{
	return type;
}

void WrongAnimal::makeSound( void ) const
{
	std::cout << "WrongAnimal sound!" << std::endl;
}
