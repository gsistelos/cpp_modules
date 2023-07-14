#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat( void );
	Cat( Cat const & other );
	~Cat();

	Cat& operator=( Cat const & other );

	void makeSound( void ) const;
};

#endif /* CAT_HPP */
