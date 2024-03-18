#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>

class ScalarConverter {
private:
  ScalarConverter(void);
  ScalarConverter(const ScalarConverter &other);

  ~ScalarConverter();

  ScalarConverter &operator=(const ScalarConverter &rhs);

  enum Type { CHAR, INT, FLOAT, DOUBLE, INVALID };

  static void (*functions[])(void);
  static std::string _literal;

  static bool isLiteral(void);
  static Type getType(void);
  static size_t getPrecision(void);

  static void fromChar(void);
  static void fromInt(void);
  static void fromFloat(void);
  static void fromDouble(void);
  static void fromInvalid(void);

public:
  static void convert(const std::string &literal);
};

#endif // SCALAR_CONVERTER_HPP
