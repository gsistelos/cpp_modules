#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat(void);
	Cat(const Cat &other);
	~Cat();

	Cat &operator=(const Cat &other);

	void makeSound(void) const;
};

#endif /* CAT_HPP */