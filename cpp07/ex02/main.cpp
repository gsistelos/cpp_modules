#include "Array.hpp"
#include <cstdlib>
#include <iostream>
#include <stdexcept>

#define MAX_VAL 750
int main(int, char **) {
  {
    Array<char> a(5);

    a[0] = 'a';
    a[1] = 'b';
    a[2] = 'c';
    a[3] = 'd';
    a[4] = 'e';

    std::cout << a << std::endl;
    std::cout << a.size() << std::endl;
  }

  {
    Array<int> a;

    try {
      a[0] = 42;
    } catch (std::out_of_range &e) {
      std::cerr << e.what() << std::endl;
    }

    std::cout << a << "%" << std::endl;
    std::cout << a.size() << std::endl;
  }

  Array<int> numbers(MAX_VAL);
  int *mirror = new int[MAX_VAL];
  srand(time(NULL));
  for (int i = 0; i < MAX_VAL; i++) {
    const int value = rand();
    numbers[i] = value;
    mirror[i] = value;
  }
  // SCOPE
  {
    Array<int> tmp = numbers;
    Array<int> test(tmp);
  }

  for (int i = 0; i < MAX_VAL; i++) {
    if (mirror[i] != numbers[i]) {
      std::cerr << "didn't save the same value!!" << std::endl;
      return 1;
    }
  }
  try {
    numbers[-2] = 0;
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
  try {
    numbers[MAX_VAL] = 0;
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }

  for (int i = 0; i < MAX_VAL; i++) {
    numbers[i] = rand();
  }
  delete[] mirror; //
  return 0;
}
