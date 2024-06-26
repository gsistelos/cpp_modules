#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB( std::string const & name ) : _name(name), _weapon(NULL)
{
}

HumanB::HumanB( std::string const & name, Weapon& weapon ) : _name(name), _weapon(&weapon)
{
}

void HumanB::attack( void )
{
	if (_weapon == NULL)
		std::cout << _name << " has no weapon to attack" << std::endl;
	else
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}

void HumanB::setWeapon( Weapon& weapon )
{
	_weapon = &weapon;
}
