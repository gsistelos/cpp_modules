#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
private:
	std::string _name;
	unsigned int _hitPoints;
	unsigned int _energyPoints;
	unsigned int _atkDamage;
public:
	ClapTrap(void);
	ClapTrap(const std::string &name);
	ClapTrap(const ClapTrap &other);
	~ClapTrap();

	ClapTrap &operator=(const ClapTrap &other);

	void setName(const std::string &name);
	void setHitPoints(unsigned int amout);
	void setEnergyPoints(unsigned int amout);
	void setAtkDamage(unsigned int amout);

	std::string  getName(void);
	unsigned int getHitPoints(void);
	unsigned int getEnergyPoints(void);
	unsigned int getAtkDamage(void);

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif /* CLAPTRAP_HPP */
