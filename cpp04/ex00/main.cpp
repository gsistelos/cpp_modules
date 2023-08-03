#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main( void )
{
	{
		Animal const * animal = new Animal();
		Animal const * dog = new Dog();
		Animal const * cat = new Cat();

		std::cout << animal->getType() << std::endl;
		std::cout << dog->getType() << std::endl;
		std::cout << cat->getType() << std::endl;

		animal->makeSound();
		cat->makeSound(); // will output the cat sound!
		dog->makeSound();

		delete animal;
		delete cat;
		delete dog;
	}

	std::cout << std::endl;

	{
		Animal const * animal = new Animal();
		Animal const * dog = new Dog();
		WrongAnimal const * cat = new WrongCat();

		std::cout << animal->getType() << std::endl;
		std::cout << dog->getType() << std::endl;
		std::cout << cat->getType() << std::endl;

		animal->makeSound();
		cat->makeSound(); // will output the WrongAnimal sound!
		dog->makeSound();

		delete animal;
		delete cat;
		delete dog;
	}

	return 0;
}
