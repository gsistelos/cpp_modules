#include "easyfind.hpp"
#include <iostream>
#include <list>
#include <set>
#include <vector>

int main(void) {
  int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  {
    std::cout << "Vector" << std::endl;

    std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));

    try {
      std::cout << *easyfind(vec, 3) << std::endl;
    } catch (std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
  }

  std::cout << std::endl;

  {
    std::cout << "List" << std::endl;

    std::list<int> lst(arr, arr + sizeof(arr) / sizeof(int));

    try {
      std::cout << *easyfind(lst, 9) << std::endl;
    } catch (std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
  }

  std::cout << std::endl;

  {
    std::cout << "Set" << std::endl;

    std::set<int> set(arr, arr + sizeof(arr) / sizeof(int));

    try {
      std::cout << *easyfind(set, -1) << std::endl;
    } catch (std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
  }
  return 0;
}
