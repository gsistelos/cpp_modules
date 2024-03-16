#include "BitcoinExchange.hpp"
#include "utils.hpp"
#include <fstream>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &rhs)
    : _exchangeRates(rhs._exchangeRates) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs) {
  if (this != &rhs)
    _exchangeRates = rhs._exchangeRates;

  return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::parseData(const std::string &filename) {
  std::ifstream file(filename.c_str());
  if (!file.is_open())
    throw std::runtime_error("Could not open file");

  std::string line;
  std::getline(file, line); // skip the first line

  while (std::getline(file, line)) {
    try {
      std::string date;
      double exchangeRate;

      std::istringstream iss(line);

      std::getline(iss, date, ',');
      if (!isDateValid(date))
        throw std::runtime_error("bad input => " + date);

      if (!(iss >> exchangeRate) || exchangeRate < 0)
        throw std::runtime_error("not a positive number.");

      if (exchangeRate > std::numeric_limits<int>::max())
        throw std::runtime_error("too large a number.");

      _exchangeRates[date] = exchangeRate;
    } catch (const std::runtime_error &e) {
      std::cout << "Error: " << e.what() << std::endl;
    }
  }
}

void BitcoinExchange::exchange(const std::string &filename) const {
  std::ifstream file(filename.c_str());
  if (!file.is_open())
    throw std::runtime_error("Could not open file");

  std::string line;
  std::getline(file, line); // skip the first line

  while (std::getline(file, line)) {
    try {
      std::string date;
      std::string separator;
      double amount;

      std::istringstream iss(line);

      if (!(iss >> date))
        throw std::runtime_error("could not read date.");

      if (!isDateValid(date))
        throw std::runtime_error("bad input => " + date);

      if (!(iss >> separator) || separator != "|")
        throw std::runtime_error("bad separator.");

      if (!(iss >> amount) || amount < 0)
        throw std::runtime_error("not a positive number.");

      if (amount > std::numeric_limits<int>::max())
        throw std::runtime_error("too large a number.");

      std::map<std::string, double>::const_iterator it =
          _exchangeRates.lower_bound(date);

      std::cout << date << " => " << amount << " = " << amount * it->second
                << std::endl;
    } catch (const std::runtime_error &e) {
      std::cout << "Error: " << e.what() << std::endl;
    }
  }
}
