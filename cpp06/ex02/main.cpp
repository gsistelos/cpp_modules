#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>
#include <iostream>

Base *generate(void) {
  srand(time(0));
  int i = rand() % 3;

  if (i == 0) {
    std::cout << "Created A" << std::endl;
    return new A;
  } else if (i == 1) {
    std::cout << "Created B" << std::endl;
    return new B;
  }

  std::cout << "Created C" << std::endl;
  return new C;
}

void identify(Base *p) {
  if (dynamic_cast<A *>(p))
    std::cout << "A" << std::endl;
  else if (dynamic_cast<B *>(p))
    std::cout << "B" << std::endl;
  else if (dynamic_cast<C *>(p))
    std::cout << "C" << std::endl;
}

void identify(Base &p) {
  try {
    dynamic_cast<A &>(p);
    std::cout << "A" << std::endl;
  } catch (const std::exception &e) {
  }

  try {
    dynamic_cast<B &>(p);
    std::cout << "B" << std::endl;
  } catch (const std::exception &e) {
  }

  try {
    dynamic_cast<C &>(p);
    std::cout << "C" << std::endl;
  } catch (const std::exception &e) {
  }
}

int main(void) {
  Base *p = generate();

  identify(p);

  identify(*p);

  delete p;

  return 0;
}
