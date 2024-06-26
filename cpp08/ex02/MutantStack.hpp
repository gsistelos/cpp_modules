#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <deque>
#include <stack>

template <typename T> class MutantStack : public std::stack<T> {
public:
  MutantStack() : std::stack<T>() {}
  MutantStack(const MutantStack &other) : std::stack<T>(other) {}

  MutantStack &operator=(const MutantStack &other) {
    if (this != &other)
      std::stack<T>::operator=(other);
    return *this;
  }

  ~MutantStack() {}

  typedef typename std::deque<T>::iterator iterator;

  // Accessing the protected member of stack, since MutantStack inherits from it
  iterator begin() { return this->c.begin(); }
  iterator end() { return this->c.end(); }
};

#endif
