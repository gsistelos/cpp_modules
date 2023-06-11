#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure( void );
	Cure( AMateria const & other );

	~Cure();

	Cure& operator=( AMateria const & other );

	AMateria* clone() const;
	void use( ICharacter& target );
};

#endif /* CURE_HPP */
