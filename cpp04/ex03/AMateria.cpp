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
	this->_type = other.getType();
}

std::string const & AMateria::getType() const
{
	return _type;
}

void AMateria::use( ICharacter& target )
{
	std::cout << "* Uses materia in " << target.getName() << " *" << std::endl;
}
