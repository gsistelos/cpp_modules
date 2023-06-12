#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria* _inventory[4];
public:
	MateriaSource( void );
	MateriaSource( MateriaSource const & other );

    ~MateriaSource();

	MateriaSource& operator=( MateriaSource const & other );

    void learnMateria( AMateria* m );
    AMateria* createMateria( std::string const & type );
};

#endif /* MATERIASOURCE_HPP */
