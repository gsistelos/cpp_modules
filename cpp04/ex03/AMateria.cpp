#include "AMateria.hpp"

AMateria::AMateria( void ) : type("default")
{
}

AMateria::AMateria( std::string const & type ) : type(type)
{
}

AMateria::AMateria( AMateria const & other )
{
	*this = other;
}

AMateria::~AMateria()
{
}

AMateria& AMateria::operator=( AMateria const & other )
{
	this->type = other.getType();
}

std::string const & AMateria::getType() const
{
	return type;
}

void AMateria::use( ICharacter& target )
{
	std::cout << "* Uses materia in " << target.getName() << " *" << std::endl;
}
