#include "AMateria.hpp"

AMateria::AMateria( void ) : _type("default")
{
}

AMateria::AMateria( std::string const & type ) : _type(type)
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
	_type = other.getType();
	return *this;
}

std::string const & AMateria::getType( void ) const
{
	return _type;
}

void AMateria::use( ICharacter& target )
{
	std::cout << "* Uses materia in " << target.getName() << " *" << std::endl;
}
