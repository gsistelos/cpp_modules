#include "ScravTrap.hpp"

ScravTrap::ScravTrap( std::string name ) : _name(name), _hitPoints(100), _energyPoints(50), _atkDamage(20) {
	std::cout << "ClapTrap " << this->_name << " created." << std::endl;
	std::cout << "> Hit Points: " << this->_hitPoints << " Energy Points: " << this->_energyPoints << std::endl;
}

ScravTrap::~ScravTrap() {
}
