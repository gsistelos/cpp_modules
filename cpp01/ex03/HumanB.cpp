#include "HumanB.hpp"

HumanB::HumanB(const std::string &name) : name(name), weapon(NULL)
{
}

HumanB::HumanB(const std::string &name, Weapon &weapon) : name(name), weapon(&weapon)
{
}

void HumanB::attack(void)
{
	if (weapon == NULL)
		std::cout << name << " has no weapon to attack" << std::endl;
	else
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
