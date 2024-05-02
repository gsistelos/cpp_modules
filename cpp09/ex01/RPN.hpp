#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPN {
public:
  // Constructors
  RPN(void);
  RPN(const RPN &src);

  // Destructor
  ~RPN();

  // Operator overloads
  RPN &operator=(const RPN &rhs);

  // Methods
  void calculate(const std::string &expression);

private:
  std::stack<double> stack;

  static const std::string operators; // possible operators
};

#endif
