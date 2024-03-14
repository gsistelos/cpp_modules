#include "iter.hpp"

#include <iostream>

void toLower(char &c) {
  if (c >= 65 && c <= 90)
    c += 32;
}

void toNegative(int &i) { i = -i; }

template <typename T> void print_array(T *arr, int size) {
  for (int i = 0; i < size; i++)
    std::cout << arr[i] << " ";
  std::cout << std::endl;
}

int main() {
  char arr1[] = {'A', 'B', 'C', 'D', 'E'};
  int arr2[] = {1, 2, 3, 4, 5};

  std::cout << "Before: " << std::endl;
  print_array(arr1, 5);
  print_array(arr2, 5);

  iter(arr1, 5, toLower);
  iter(arr2, 5, toNegative);

  std::cout << "After: " << std::endl;
  print_array(arr1, 5);
  print_array(arr2, 5);
  return 0;
}
