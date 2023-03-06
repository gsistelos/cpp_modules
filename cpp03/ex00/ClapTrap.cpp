#include "ClapTrap.hpp"

ClapTrap::ClapTrap( std::string name ) : _name(name), _hitPoints(10), _energyPoints(10), _atkDamage(0) {
	std::cout << "ClapTrap " << this->_name << " created." << std::endl;
	std::cout << "> Hit Points: " << this->_hitPoints << " Energy Points: " << this->_energyPoints << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << this->_name << " destroyed." << std::endl;
	std::cout << "> Hit Points: " << this->_hitPoints << " Energy Points: " << this->_energyPoints << std::endl;
}

void ClapTrap::attack( const std::string& target ) {
	if (this->_hitPoints == 0) {
		std::cout << "ClapTrap " << this->_name << " has no hit points left to attack!" << std::endl;
		return ;
	}
	if (this->_energyPoints == 0) {
		std::cout << "ClapTrap " << this->_name << " has no energy points left to attack!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_atkDamage << " points of damage!" << std::endl;
	this->_energyPoints -= 1;
	std::cout << "> Hit Points: " << this->_hitPoints << " Energy Points: " << this->_energyPoints << std::endl;
}

void ClapTrap::takeDamage( unsigned int amount ) {
	if (this->_hitPoints == 0) {
		std::cout << "ClapTrap " << this->_name << " is already dead!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " took " << amount << " points of damage!" << std::endl;
	if (amount > this->_hitPoints)
		this->_hitPoints = 0;
	else
		this->_hitPoints -= amount;
	std::cout << "> Hit Points: " << this->_hitPoints << " Energy Points: " << this->_energyPoints << std::endl;
}

void ClapTrap::beRepaired( unsigned int amount ) {
	if (this->_hitPoints == 0) {
		std::cout << "ClapTrap " << this->_name << " has no hit points left to repair itself!" << std::endl;
		return ;
	}
	if (this->_energyPoints == 0) {
		std::cout << "ClapTrap " << this->_name << " has no energy points left to repair itself!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " repairs itself " << amount << " hit points!" << std::endl;
	this->_hitPoints += amount;
	this->_energyPoints -= 1;
	std::cout << "> Hit Points: " << this->_hitPoints << " Energy Points: " << this->_energyPoints << std::endl;
}
