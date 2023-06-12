#include "Ice.hpp"

Ice::Ice( void ) : AMateria("ice")
{
}

Ice::Ice( AMateria const & other )
{
	*this = other;
}

Ice& Ice::operator=( AMateria const & other )
{
	_type = other.getType();
	return *this;
}

Ice::~Ice()
{
}

AMateria* Ice::clone( void ) const
{
	return new Ice(*this);
}

void Ice::use( ICharacter& target )
{
	std::cout << "*  shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
