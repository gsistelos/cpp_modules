#ifndef WRONGAANIMAL_HPP
#define WRONGAANIMAL_HPP

#include <iostream>

class WrongAAnimal
{
protected:
	std::string type;
public:
	WrongAAnimal(void);
	WrongAAnimal(const std::string &name);
	WrongAAnimal(const WrongAAnimal &other);
	~WrongAAnimal();

	WrongAAnimal &operator=(const WrongAAnimal &other);

	std::string getType(void) const;

	void makeSound(void) const = 0;
};

#endif /* WRONGAANIMAL_HPP */
