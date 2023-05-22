#include "Cure.hpp"

Cure::Cure(void) : type("cure"), useString({"* heals ", "'s wounds *"})
{
}

AMateria* Cure::clone() const
{
	Cure* other = new Cure;

	other->type = type;
	other->useString = useString;
	return other;
}
