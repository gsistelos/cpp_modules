#include "PmergeMe.hpp"
#include <iomanip>
#include <iostream>

int main(int argc, char *argv[]) {
  PmergeMe pm;

  try {
    pm.parseArgs(argc, argv);
  } catch (const std::exception &e) {
    std::cerr << "Error" << std::endl;
    return 1;
  }

  std::cout << "Before: " << pm << std::endl;

  pm.mergeMe();

  std::cout << "After: " << pm << std::endl;

  std::cout << "Time to process a range of " << pm.getVec().size()
            << " elements with std::vector : " << std::fixed
            << std::setprecision(6) << pm.getVecTime() << "s" << std::endl;

  std::cout << "Time to process a range of " << pm.getDeq().size()
            << " elements with std::deque : " << std::fixed
            << std::setprecision(6) << pm.getDeqTime() << "s" << std::endl;

  return 0;
}
