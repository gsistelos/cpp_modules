#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++) {
		materia[i] = NULL;
	}
}

MateriaSource::MateriaSource(MateriaSource& other)
{
	*this = other;
}

MateriaSource::~MateriaSource()
{
}

MateriaSource& MateriaSource::operator=(MateriaSource& other)
{
	for (int i = 0; i < 4; i++) {
		materia[i] = other.materia[i];
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++) {
		if (materia[i] == NULL) {
			materia[i] = m;
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 3; i >= 0; i--) {
		if (materia[i]->getType() == type) {
			return materia[i]->clone();
		}
	}
}
