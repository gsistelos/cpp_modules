#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
	{
		const Animal* animal = new Animal();
		const Animal* dog = new Dog();
		const Animal* cat = new Cat();

		std::cout << dog->getType() << " " << std::endl;
		std::cout << cat->getType() << " " << std::endl;
		cat->makeSound(); //will output the cat sound!
		dog->makeSound();
		animal->makeSound();

		delete animal;
		delete cat;
		delete dog;
	}
	std::cout << std::endl;
	{
		const Animal* animal = new Animal();
		const Animal* dog = new Dog();
		const WrongAnimal* cat = new WrongCat();
	
		std::cout << dog->getType() << " " << std::endl;
		std::cout << cat->getType() << " " << std::endl;
		cat->makeSound(); //will output the wrongAnimal sound!
		dog->makeSound();
		animal->makeSound();
	
		delete animal;
		delete cat;
		delete dog;
	}

	return 0;
}
