#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPN {
public:
  RPN(void);
  RPN(const RPN &src);
  ~RPN();

  RPN &operator=(const RPN &rhs);

  void calculate(const std::string &expression);

private:
  std::stack<double> stack;

  static const std::string operators; // possible operators
};

#endif
