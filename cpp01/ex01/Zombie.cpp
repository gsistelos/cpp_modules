#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie( void )
{
}

Zombie::~Zombie()
{
	std::cout << "Destroyed: " << name << std::endl;
}

void Zombie::setName( std::string name )
{
	this->name = name;
}

void Zombie::announce( void )
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
