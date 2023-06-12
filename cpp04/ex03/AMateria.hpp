#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
protected:
	std::string _type;
public:
	AMateria( void );
	AMateria( std::string const & type );
	AMateria( AMateria const & other );

	virtual ~AMateria();

	AMateria& operator=( AMateria const & other );

	std::string const & getType( void ) const;
	virtual AMateria* clone( void ) const = 0;
	virtual void use( ICharacter& target );
};

#endif /* AMATERIA_HPP */
