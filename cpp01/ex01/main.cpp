#include "Zombie.hpp"

int	main(void) {
	int N = 10;
	Zombie* gguedesHorde = zombieHorde(N, "gguedes");

	for (int i = 0; i < N; i++) {
		gguedesHorde[i].announce();
	}

	delete[] gguedesHorde;
	return (0);
}
