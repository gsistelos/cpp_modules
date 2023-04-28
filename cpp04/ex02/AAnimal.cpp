#include "AAnimal.hpp"

AAnimal::AAnimal(void) : type("AAnimal")
{
	std::cout << "AAnimal: Default constructor called." << std::endl;
}

AAnimal::AAnimal(const std::string &type) : type(type)
{
	std::cout << "AAnimal: type constructor called." << std::endl;
}

AAnimal::AAnimal(const AAnimal &other) : type(other.type)
{
	std::cout << "AAnimal: Copy constructor called." << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal: Destructor called." << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
	type = other.type;
	std::cout << "AAnimal: Assignment operator called." << std::endl;
	return *this;
}

std::string AAnimal::getType(void) const
{
	return type;
}
