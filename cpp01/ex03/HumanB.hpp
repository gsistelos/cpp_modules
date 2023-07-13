#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
private:
	std::string _name;
	Weapon* _weapon;
public:
	HumanB( std::string const & name );
	HumanB( std::string const & name, Weapon& weapon );

	void attack( void );
	void setWeapon( Weapon& weapon );
};

#endif /* HUMANB_HPP */
