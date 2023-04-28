#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

#define N 20

int main(void)
{
	{
		const AAnimal* animals[N];
		for (int i = 0; i < N / 2; i++) {
			animals[i] = new Dog();
		}
		for (int i = N / 2; i < N; i++) {
			animals[i] = new Cat();
		}
		for (int i = 0; i < N; i++) {
			std::cout << animals[i]->getType() << " " << std::endl;
			animals[i]->makeSound();
		}
		for (int i = 0; i < N; i++) {
			delete animals[i];
		}
	}
	/*
	std::cout << std::endl;
	{
		const AAnimal animal;
		std::cout << animal.getType() << " " << std::endl;
		animal.makeSound();
	}
	*/
	return 0;
}