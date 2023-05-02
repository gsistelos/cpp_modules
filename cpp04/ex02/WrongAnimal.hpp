#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
protected:
	std::string type;
public:
	WrongAnimal(void);
	WrongAnimal(const std::string &name);
	WrongAnimal(const WrongAnimal &other);
	~WrongAnimal();

	WrongAnimal &operator=(const WrongAnimal &other);

	std::string getType(void) const;

	void makeSound(void);
};

#endif /* WRONGANIMAL_HPP */
