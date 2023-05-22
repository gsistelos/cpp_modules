#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure(void);
	Cure(AMateria& other);
	/* PURE VIRTUAL DISTRUCTOR? */

	AMateria& operator=(AMateria& other);

	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
};

#endif /* CURE_HPP */
