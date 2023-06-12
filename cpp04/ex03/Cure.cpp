#include "Cure.hpp"

Cure::Cure( void ) : AMateria("cure")
{
}

Cure::Cure( AMateria const & other )
{
	*this = other;
}

Cure& Cure::operator=( AMateria const & other )
{
	_type = other.getType();
	return *this;
}

Cure::~Cure()
{
}

AMateria* Cure::clone( void ) const
{
	return new Cure(*this);
}

void Cure::use( ICharacter& target )
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
