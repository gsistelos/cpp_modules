#include "utils.hpp"
#include <cstdio>

bool isDateValid(const std::string &date) {
  int day, month, year;

  if (date < "2009-01-02" || date > "2022-03-29")
    return false;

  if (sscanf(date.c_str(), "%4d-%2d-%2d", &year, &month, &day) != 3)
    return false;

  if (month < 1 || month > 12)
    return false;

  if (day < 1)
    return false;

  if (month == 2) {
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
      if (day > 29)
        return false;
    } else {
      if (day > 28)
        return false;
    }
  } else if (month == 4 || month == 6 || month == 9 || month == 11) {
    if (day > 30)
      return false;
  } else {
    if (day > 31)
      return false;
  }

  return true;
}

bool isPositiveNumber(const std::string &str) {
  bool dot = false;

  for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
    if (!std::isdigit(*it)) {
      if (*it == '.' && dot == false) {
        dot = true;
        continue;
      }
      return false;
    }
  }

  return true;
}
