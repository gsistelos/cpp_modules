#include "HumanB.hpp"

HumanB::HumanB(const std::string &name)
{
	this->name = name;
}

HumanB::HumanB(const std::string &name, Weapon &weapon)
{
	this->name = name;
	this->weapon = &weapon;
}

void HumanB::attack(void)
{
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
