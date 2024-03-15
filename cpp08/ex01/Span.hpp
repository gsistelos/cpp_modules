#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span {
public:
  Span(void);
  Span(unsigned int size);
  ~Span(void);

  Span(const Span &rhs);

  Span &operator=(const Span &rhs);

  void addNumber(int number);
  void addNumber(const std::vector<int>::iterator &begin,
                 const std::vector<int>::iterator &end);
  int shortestSpan(void) const;
  int longestSpan(void) const;

private:
  std::vector<int> _vec;
  unsigned int _size;
};

#endif // SPAN_HPP
