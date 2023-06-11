#include "Cure.hpp"

Cure::Cure( void ) : AMateria("cure")
{
}

Cure::Cure( Cure const & other )
{
	*this = other;
}

Cure& Cure::operator=( Cure const & other )
{
	this->type = other.getType();
}

Cure::~Cure()
{
}

AMateria* Cure::clone() const
{
	Cure* cure = new Cure;

	*cure = *this;
	return cure;
}

void Cure::use( ICharacter& target )
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
