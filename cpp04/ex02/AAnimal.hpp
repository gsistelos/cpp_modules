#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class AAnimal
{
protected:
	std::string type;
public:
	AAnimal(void);
	AAnimal(const std::string &name);
	AAnimal(const AAnimal &other);
	virtual ~AAnimal();

	AAnimal &operator=(const AAnimal &other);

	std::string getType(void) const;

	virtual void makeSound(void) const = 0;
};

#endif /* AANIMAL_HPP */
