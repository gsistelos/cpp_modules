#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice( void );
	Ice( Ice const & other );

	~Ice();

	Ice& operator=( Ice const & other );

	AMateria* clone() const;
	void use( ICharacter& target );
};

#endif /* ICE_HPP */
