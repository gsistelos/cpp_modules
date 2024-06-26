#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain* brain;

public:
	Cat( void );
	Cat( Cat const & other );
	~Cat();

	Cat& operator=( Cat const & other );

	void makeSound( void ) const;
};

#endif /* CAT_HPP */
