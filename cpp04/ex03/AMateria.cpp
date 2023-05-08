#include "AMateria.hpp"

AMateria::AMateria(std::string &type) : type(type)
{
}

AMateria::~AMateria()
{
}

AMateria::getType()
{
	return type;
}

AMateria::use(ICharacter& target)
{
	std::cout << useString[0] << target.getName() << useString[1] << std::endl;
}
