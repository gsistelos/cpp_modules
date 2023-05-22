#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria* materia[4];
public:
	MateriaSource(void);
	MateriaSource(MateriaSource& other);
	/* PURE VIRTUAL DISTRUCTOR? */

	MateriaSource& operator=(MateriaSource& other);

	virtual void learnMateria(AMateria* m);
	virtual AMateria* createMateria(std::string const & type);
};

#endif /* MATERIASOURCE_HPP */
