#include "HumanB.hpp"

HumanB::HumanB( std::string const & name ) : name(name), weapon(NULL)
{
}

HumanB::HumanB( std::string const & name, Weapon& weapon ) : name(name), weapon(&weapon)
{
}

void HumanB::attack( void )
{
	if (weapon == NULL)
		std::cout << name << " has no weapon to attack" << std::endl;
	else
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void HumanB::setWeapon( Weapon& weapon )
{
	this->weapon = &weapon;
}
