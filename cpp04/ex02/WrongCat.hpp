#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAAnimal.hpp"

class WrongCat : public WrongAAnimal
{
public:
	WrongCat(void);
	WrongCat(const WrongCat &other);
	~WrongCat();

	WrongCat &operator=(const WrongCat &other);

	void makeSound(void) const;
};

#endif /* WRONGCAT_HPP */
