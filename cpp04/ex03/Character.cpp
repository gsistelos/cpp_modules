#include "Character.hpp"

Character::Character(void) : name("unnamed")
{
	for (int i = 0; i < 4; i++) {
		inventory[i] = NULL;
	}
}

Character::Character(std::string& name) : name(name)
{
	for (int i = 0; i < 4; i++) {
		inventory[i] = NULL;
	}
}

Character::~Character()
{
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++) {
		if (inventory[i]) {
			inventory[i] = m;
			return ;
		}
	}
}

void Character::unequip(int idx)
{
	inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (inventory[idx] == NULL)
		return ;
	inventory[idx]->use(target);
}
