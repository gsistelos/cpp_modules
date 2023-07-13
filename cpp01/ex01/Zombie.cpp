#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie( void )
{
}

Zombie::~Zombie()
{
	std::cout << "Destroyed: " << _name << std::endl;
}

void Zombie::setName( std::string name )
{
	_name = name;
}

void Zombie::announce( void )
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
