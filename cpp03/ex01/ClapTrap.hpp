#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
protected:
	std::string _name;
	unsigned int _hitPoints;
	unsigned int _energyPoints;
	unsigned int _atkDamage;
public:
	ClapTrap( void );
	ClapTrap( std::string const & name );
	ClapTrap( ClapTrap const & other );
	~ClapTrap();

	ClapTrap& operator=( ClapTrap const & other );

	void attack( std::string const & target );
	void takeDamage( unsigned int amount );
	void beRepaired( unsigned int amount );
};

#endif /* CLAPTRAP_HPP */
