#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void randomChump( std::string name );

int main( void )
{
	Zombie* gguedes = newZombie("gguedes");
	gguedes->announce();
	delete gguedes;

	randomChump("vsergio");
	return 0;
}
