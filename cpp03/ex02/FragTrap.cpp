#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap( void ) : ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 100;
	_atkDamage = 30;
	std::cout << "FragTrap " << _name << " created from default constructor." << std::endl;
}

FragTrap::FragTrap( std::string const & name ) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_atkDamage = 30;
	std::cout << "FragTrap " << _name << " created from name constructor." << std::endl;
}

FragTrap::FragTrap( FragTrap const & other ) : ClapTrap(other)
{
	std::cout << "FragTrap " << _name << " created from copy constructor." << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " destroyed." << std::endl;
}

FragTrap& FragTrap::operator=( FragTrap const & other)
{
	ClapTrap::operator=(other);
	std::cout << "FragTrap " << _name << " assigned from operator=." << std::endl;
	return *this;
}

void FragTrap::highFiveGuys( void )
{
	std::cout << _name << " high five time!" << std::endl;
}
