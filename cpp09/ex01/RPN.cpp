#include "RPN.hpp"

#include <iostream>
#include <sstream>

const std::string RPN::operators = "+-*/";

RPN::RPN(void) {}

RPN::RPN(const RPN &src) : stack(src.stack) {}

RPN::~RPN() {}

RPN &RPN::operator=(const RPN &rhs) {
  if (this != &rhs) {
    stack = rhs.stack;
  }

  return *this;
}

void RPN::calculate(const std::string &expression) {
  std::istringstream iss(expression);

  std::string token;

  while (iss >> token) {
    if (token.length() > 1) {
      throw std::exception();
    }

    char c = token[0];

    if (operators.find(c) != std::string::npos) {
      if (stack.size() < 2) {
        throw std::exception();
      }

      double rhs = stack.top();
      stack.pop();

      double lhs = stack.top();
      stack.pop();

      double result = 0;

      switch (token[0]) {
      case '+':
        result = lhs + rhs;
        break;
      case '-':
        result = lhs - rhs;
        break;
      case '*':
        result = lhs * rhs;
        break;
      case '/':
        result = lhs / rhs;
        break;
      }

      stack.push(result);
    } else if (std::isdigit(c)) {
      stack.push(c - '0');
    } else {
      throw std::exception();
    }
  }

  std::cout << stack.top() << std::endl;
}
