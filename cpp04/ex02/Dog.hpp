#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
private:
	Brain *brain;
public:
	Dog(void);
	Dog(const Dog &other);
	~Dog();

	Dog &operator=(const Dog &other);

	void makeSound(void) const;
};

#endif /* DOG_HPP */
