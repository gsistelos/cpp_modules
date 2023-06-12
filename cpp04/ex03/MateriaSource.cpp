#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void )
{
	for (int i = 0; i < 4; i++) {
		_inventory[i] = NULL;
	}
}

MateriaSource::MateriaSource( MateriaSource const & other )
{
	*this = other;
}

MateriaSource::~MateriaSource()
{
}

MateriaSource& MateriaSource::operator=( MateriaSource const & other )
{
	for (int i = 0; i < 4; i++) {
		delete _inventory[i];
		_inventory[i] = other._inventory[i]->clone();
	}
	return *this;
}

void MateriaSource::learnMateria( AMateria* m )
{
	for (int i = 0; i < 4; i++) {
		if (_inventory[i] == NULL) {
			_inventory[i] = m;
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria( std::string const & type )
{
	for (int i = 3; i >= 0; i--) {
		if (_inventory[i] != NULL && _inventory[i]->getType() == type) {
			return _inventory[i]->clone();
		}
	}
	return NULL;
}
