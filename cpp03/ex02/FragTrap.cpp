#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	setHitPoints(100);
	setEnergyPoints(100);
	setAtkDamage(30);
	std::cout << "FragTrap " << getName() << " created from default constructor." << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	setHitPoints(100);
	setEnergyPoints(100);
	setAtkDamage(30);
	std::cout << "FragTrap " << getName() << " created from name constructor." << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap " << getName() << " created from copy constructor." << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << getName() << " destroyed." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	ClapTrap::operator=(other);
	std::cout << "FragTrap " << getName() << " assigned from operator=." << std::endl;
	return *this;
}

void FragTrap::attack(const std::string &target)
{
	if (getHitPoints() == 0) {
		std::cout << "FragTrap " << getName() << " has no hit points left to attack!" << std::endl;
		return ;
	}
	if (getEnergyPoints() == 0) {
		std::cout << "FragTrap " << getName() << " has no energy points left to attack!" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << getName() << " attacks " << target << ", causing " << getAtkDamage() << " points of damage!" << std::endl;
	setEnergyPoints(getEnergyPoints() - 1);
}

void FragTrap::highFiveGuys(void)
{
	std::cout << getName() << " high five time!" << std::endl;
}
