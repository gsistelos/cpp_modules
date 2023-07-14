#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>

class AAnimal
{
protected:
	std::string type;
public:
	AAnimal( void );
	AAnimal( std::string const & name );
	AAnimal( AAnimal const & other );
	virtual ~AAnimal();

	AAnimal& operator=( AAnimal const & other );

	std::string getType( void ) const;

	virtual void makeSound( void ) const = 0;
};

#endif /* AANIMAL_HPP */
