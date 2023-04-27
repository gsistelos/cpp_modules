#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

#define N 20

int main(void)
{
	{
		const Animal* animals = new Animal[N];
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
		delete[] animals;
	}

	return 0;
}