#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	setHitPoints(100);
	setEnergyPoints(50);
	setAtkDamage(20);
	std::cout << "ScavTrap " << getName() << " created from default constructor." << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	setHitPoints(100);
	setEnergyPoints(50);
	setAtkDamage(20);
	std::cout << "ScavTrap " << getName() << " created from name constructor." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap " << getName() << " created from copy constructor." << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << getName() << " destroyed." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	ClapTrap::operator=(other);
	std::cout << "ScavTrap " << getName() << " assigned from operator=." << std::endl;
	return *this;
}

void ScavTrap::attack(const std::string &target)
{
	if (getHitPoints() == 0) {
		std::cout << "ScavTrap " << getName() << " has no hit points left to attack!" << std::endl;
		return ;
	}
	if (getEnergyPoints() == 0) {
		std::cout << "ScavTrap " << getName() << " has no energy points left to attack!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing " << getAtkDamage() << " points of damage!" << std::endl;
	setEnergyPoints(getEnergyPoints() - 1);
}

void ScavTrap::guardGate(void)
{
	std::cout << getName() << " is now in Gate keeper mode!" << std::endl;
}
