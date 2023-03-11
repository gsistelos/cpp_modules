#include "ClapTrap.hpp"

int main( void ) {
	ClapTrap* gguedes;


	gguedes = new ClapTrap("gguedes");
	gguedes->attack("Malenia");
	gguedes->takeDamage(999);
	gguedes->attack("Malenia");
	gguedes->beRepaired(10);
	delete gguedes;
	std::cout << std::endl;

	gguedes = new ClapTrap("gguedes");
	gguedes->attack("Moon Lord");
	gguedes->beRepaired(10);
	gguedes->takeDamage(19);
	gguedes->beRepaired(1);
	gguedes->attack("Moon Lord");
	gguedes->takeDamage(2);
	gguedes->beRepaired(1);
	gguedes->attack("Moon Lord");
	delete gguedes;
	std::cout << std::endl;

	gguedes = new ClapTrap("gguedes");
	gguedes->attack("Sans");
	gguedes->attack("Sans");
	gguedes->attack("Sans");
	gguedes->attack("Sans");
	gguedes->attack("Sans");
	gguedes->attack("Sans");
	gguedes->attack("Sans");
	gguedes->attack("Sans");
	gguedes->attack("Sans");
	gguedes->attack("Sans");
	gguedes->attack("Sans");
	gguedes->beRepaired(10);
	gguedes->takeDamage(10);
	gguedes->beRepaired(1);
	gguedes->attack("Sans");
	delete gguedes;
	return 0;
}
