#include "Span.hpp"
#include <cstdlib>
#include <iostream>

int main(void) {
  {
    Span sp = Span(100);

    try {
      sp.shortestSpan();
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }

  {
    Span sp = Span(5);

    sp.addNumber(42);
    sp.addNumber(9);
    sp.addNumber(11);
    sp.addNumber(31);
    sp.addNumber(21);

    try {
      sp.addNumber(10);
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }

    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;
  }

  {
    Span sp = Span(10000);
    std::vector<int> vec;

    srand(time(NULL));
    for (int i = 0; i < 10000; i++) {
      vec.push_back(rand() % 99999);
    }

    try {
      sp.addNumber(vec.begin(), vec.end());

      std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
      std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }

  return 0;
}
