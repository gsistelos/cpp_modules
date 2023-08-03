#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <string>

class WrongAnimal
{
protected:
	std::string type;

public:
	WrongAnimal( void );
	WrongAnimal( std::string const & name );
	WrongAnimal( WrongAnimal const & other );
	~WrongAnimal();

	WrongAnimal& operator=( WrongAnimal const & other );

	std::string getType( void ) const;

	void makeSound( void ) const;
};

#endif /* WRONG_ANIMAL_HPP */
