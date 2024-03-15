#include "Span.hpp"
#include <algorithm>
#include <stdexcept>

Span::Span(void) : _size(0) {}

Span::Span(unsigned int size) : _size(size) {}

Span::~Span(void) {}

Span::Span(const Span &rhs) : _vec(rhs._vec), _size(rhs._size) {}

Span &Span::operator=(const Span &rhs) {
  if (this != &rhs) {
    _vec = rhs._vec;
    _size = rhs._size;
  }

  return *this;
}

void Span::addNumber(int n) {
  if (_vec.size() == _size)
    throw std::runtime_error("Vector is full!");

  _vec.push_back(n);
}

void Span::addNumber(const std::vector<int>::iterator &begin,
                     const std::vector<int>::iterator &end) {
  unsigned int total = std::distance(begin, end) + _vec.size();
  if (total > _size)
    throw std::runtime_error("Not enough space!");

  _vec.insert(_vec.end(), begin, end);
}

int Span::shortestSpan(void) const {
  if (_vec.size() < 2)
    throw std::runtime_error("Vector is too small!");

  std::vector<int> tmp = _vec;

  std::sort(tmp.begin(), tmp.end());
  int shortest = tmp[1] - tmp[0];

  for (unsigned int i = 1; i < tmp.size(); i++) {
    if (tmp[i] - tmp[i - 1] < shortest)
      shortest = tmp[i] - tmp[i - 1];
  }

  return shortest;
}

int Span::longestSpan(void) const {
  if (_vec.size() < 2)
    throw std::runtime_error("Vector is too small!");

  std::vector<int> tmp = _vec;

  std::sort(tmp.begin(), tmp.end());

  return tmp[tmp.size() - 1] - tmp[0];
}
