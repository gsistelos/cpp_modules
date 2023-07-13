#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain *brain;
public:
	Dog(void);
	Dog(const Dog &other);
	~Dog();

	Dog &operator=(const Dog &other);

	void makeSound(void) const;
	std::string getIdea(void) const;
};

#endif /* DOG_HPP */
