#include "RPN.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " expression" << std::endl;
    return 1;
  }

  RPN rpn;

  try {
    rpn.calculate(argv[1]);
  } catch (const std::exception &e) {
    std::cerr << "Error" << std::endl;
    return 1;
  }

  return 0;
}
