#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>

#define N 10

int main( void )
{
	Animal* animals[N];

	for (size_t i = 0; i < N / 2; i++) {
		animals[i] = new Dog();
	}
	for (size_t i = N / 2; i < N; i++) {
		animals[i] = new Cat();
	}

	std::cout << std::endl;

	Dog* dog = new Dog();

	Dog* newDog = new Dog(*dog);

	delete dog;
	delete newDog;

	std::cout << std::endl;

	for (size_t i = 0; i < N; i++) {
		delete animals[i];
	}

	return 0;
}
