#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("Default"), _hitPoints(10), _energyPoints(10), _atkDamage(0)
{
	std::cout << "ClapTrap " << _name << " created from default constructor." << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : _name(name), _hitPoints(10), _energyPoints(10), _atkDamage(0)
{
	std::cout << "ClapTrap " << _name << " created from name constructor." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
	: _name(other._name), _hitPoints(other._hitPoints),
	_energyPoints(other._energyPoints), _atkDamage(other._atkDamage)
{
	std::cout << "ClapTrap " << _name << " created from copy constructor." << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " destroyed." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_atkDamage = other._atkDamage;
	std::cout << "ClapTrap " << _name << " assingned from operator=." << std::endl;
	return *this;
}

void ClapTrap::attack(const std::string &target)
{
	if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name << " has no hit points left to attack!" << std::endl;
	} else if (_energyPoints == 0) {
		std::cout << "ClapTrap " << _name << " has no energy points left to attack!" << std::endl;
	} else {
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _atkDamage << " points of damage!" << std::endl;
		_energyPoints -= 1;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " took " << amount << " points of damage!" << std::endl;
	if (amount > _hitPoints)
		_hitPoints = 0;
	else
		_hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name << " has no hit points left to repair itself!" << std::endl;
	} else if (_energyPoints == 0) {
		std::cout << "ClapTrap " << _name << " has no energy points left to repair itself!" << std::endl;
	} else {
		std::cout << "ClapTrap " << _name << " repairs itself " << amount << " hit points!" << std::endl;
		if (_hitPoints > _hitPoints + amount)
			_hitPoints = 4294967295;
		else
			_hitPoints += amount;
		_energyPoints -= 1;
	}
}
