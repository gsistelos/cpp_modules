#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void randomChump( std::string name );

int main( void ) {
	//gguedes zombie is allocated at the heap, thus it must be destroyed using delete
	Zombie* gguedes = newZombie("gguedes");
	gguedes->announce();
	delete gguedes;

	//vsergio zombie is allocated at the stack, thus it is destroyed when its out of scope
	randomChump("vsergio");
	return 0;
}
