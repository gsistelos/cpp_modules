#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
protected:
	std::string type;

public:
	Animal( void );
	Animal( std::string const & name );
	Animal( Animal const & other );
	virtual ~Animal();

	Animal& operator=( Animal const & other );

	std::string getType( void ) const;

	virtual void makeSound( void ) const;
};

#endif /* ANIMAL_HPP */
