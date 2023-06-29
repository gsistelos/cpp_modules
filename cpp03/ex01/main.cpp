#include "ScavTrap.hpp"

int main(void)
{
	{
		ScavTrap gguedes;
		ScavTrap assing(gguedes);
		gguedes = assing;
	}
	std::cout << std::endl;
	{
		ScavTrap gguedes("gguedes");
		gguedes.attack("Malenia");
		gguedes.takeDamage(999);
		gguedes.attack("Malenia");
		gguedes.beRepaired(10);
	}
	std::cout << std::endl;
	{
		ScavTrap gguedes("gguedes");
		gguedes.attack("Moon Lord");
		gguedes.beRepaired(10);
		gguedes.takeDamage(19);
		gguedes.beRepaired(1);
		gguedes.attack("Moon Lord");
		gguedes.takeDamage(2);
		gguedes.beRepaired(1);
		gguedes.attack("Moon Lord");
	}
	std::cout << std::endl;
	{
		ScavTrap gguedes("gguedes");
		for(int i = 0; i < 11; i++) {
			gguedes.attack("Sans");
		}
		gguedes.beRepaired(10);
		gguedes.takeDamage(10);
		gguedes.beRepaired(1);
		gguedes.attack("Sans");
	}
	return 0;
}
