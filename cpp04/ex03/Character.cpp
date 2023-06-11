#include "Character.hpp"

Character::Character( void ) : _name("default")
{
	for (int i = 0; i < 4; i++) {
		_inventory[i] = NULL;
	}
}

Character::Character( std::string& name ) : _name(name)
{
	for (int i = 0; i < 4; i++) {
		_inventory[i] = NULL;
	}
}

Character::Character( ICharacter const & other )
{
	*this = other;
}

Character::~Character()
{
}

Character& Character::operator=( ICharacter const & other )
{
	this->_name = other.getName();
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
}

void Character::equip( AMateria* m )
{
	for (int i = 0; i < 4; i++) {
		if (_inventory[i] == NULL) {
			_inventory[i] = m;
			return ;
		}
	}
}

void Character::unequip( int idx )
{
	_inventory[idx] = NULL;
}

void Character::use( int idx, ICharacter& target )
{
	if (_inventory[idx] == NULL)
		return ;
	_inventory[idx]->use(target);
}
