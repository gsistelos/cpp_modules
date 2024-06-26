#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap( void ) : ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 50;
	_atkDamage = 20;
	std::cout << "ScavTrap " << _name << " created from default constructor." << std::endl;
}

ScavTrap::ScavTrap( std::string const & name ) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_atkDamage = 20;
	std::cout << "ScavTrap " << _name << " created from name constructor." << std::endl;
}

ScavTrap::ScavTrap( ScavTrap const & other ) : ClapTrap(other)
{
	std::cout << "ScavTrap " << _name << " created from copy constructor." << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " destroyed." << std::endl;
}

ScavTrap& ScavTrap::operator=( ScavTrap const & other )
{
	ClapTrap::operator=(other);
	std::cout << "ScavTrap " << _name << " assigned from operator=." << std::endl;
	return *this;
}

void ScavTrap::attack( std::string const & target )
{
	if (_hitPoints == 0) {
		std::cout << "ScavTrap " << _name << " has no hit points left to attack!" << std::endl;
	} else if (_energyPoints == 0) {
		std::cout << "ScavTrap " << _name << " has no energy points left to attack!" << std::endl;
	} else {
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _atkDamage << " points of damage!" << std::endl;
		_energyPoints -= 1;
	}
}

void ScavTrap::guardGate( void )
{
	std::cout << _name << " is now in Gate keeper mode!" << std::endl;
}
