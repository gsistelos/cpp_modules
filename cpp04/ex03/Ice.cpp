#include "Ice.hpp"

Ice::Ice( void ) : AMateria("ice")
{
}

Ice::Ice( Ice const & other )
{
	*this = other;
}

Ice& Ice::operator=( Ice const & other )
{
	this->type = other.getType();
}

Ice::~Ice()
{
}

AMateria* Ice::clone() const
{
	Ice* ice = new Ice;

	*ice = *this;
	return ice;
}

void Ice::use( ICharacter& target )
{
	std::cout << "*  shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
