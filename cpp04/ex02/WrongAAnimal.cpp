#include "WrongAAnimal.hpp"

WrongAAnimal::WrongAAnimal(void) : type("WrongAAnimal")
{
	std::cout << "WrongAAnimal: Default constructor called." << std::endl;
}

WrongAAnimal::WrongAAnimal(const std::string &type) : type(type)
{
	std::cout << "WrongAAnimal: type constructor called." << std::endl;
}

WrongAAnimal::WrongAAnimal(const WrongAAnimal &other) : type(other.type)
{
	std::cout << "WrongAAnimal: Copy constructor called." << std::endl;
}

WrongAAnimal::~WrongAAnimal()
{
	std::cout << "WrongAAnimal: Destructor called." << std::endl;
}

WrongAAnimal &WrongAAnimal::operator=(const WrongAAnimal &other)
{
	type = other.type;
	std::cout << "WrongAAnimal: Assignment operator called." << std::endl;
	return *this;
}

std::string WrongAAnimal::getType(void) const
{
	return type;
}
