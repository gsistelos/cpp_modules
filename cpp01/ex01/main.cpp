#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main( void )
{
	int N = 10;
	Zombie* gguedesHorde = zombieHorde(N, "gguedes");

	for (int i = 0; i < N; i++) {
		gguedesHorde[i].announce();
	}
	delete[] gguedesHorde;
	return 0;
}
