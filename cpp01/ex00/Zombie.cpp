#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie( std::string name ) : name(name)
{
}

Zombie::~Zombie()
{
	std::cout << "Destroyed: " << name << std::endl;
}

void Zombie::announce( void )
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
