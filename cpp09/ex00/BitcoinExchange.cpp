#include "BitcoinExchange.hpp"

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <stdexcept>

BitcoinExchange::BitcoinExchange(void) {
  std::ifstream file("data.csv");
  if (!file.is_open()) {
    throw std::runtime_error("Could not open data.csv.");
  }

  std::string line;

  // Ignore the first line
  std::getline(file, line);

  // Read file line by line
  while (std::getline(file, line)) {
    // Split date and price
    std::size_t pos = line.find(',');
    if (pos == std::string::npos) {
      throw std::runtime_error("data.csv: Invalid file format.");
    }

    std::string date = line.substr(0, pos);
    if (price_ot.count(date)) {
      throw std::runtime_error("Duplicate date: " + date + ".");
    }

    std::string price_str = line.substr(pos + 1);

    double price = std::strtod(price_str.c_str(), NULL);

    // Store date and price
    this->price_ot[date] = price;
  }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
    : price_ot(src.price_ot) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs) {
  if (this != &rhs) {
    this->price_ot = rhs.price_ot;
  }

  return *this;
}

void BitcoinExchange::exchange(const std::string &filename) {
  std::ifstream file(filename.c_str());
  if (!file.is_open()) {
    throw std::runtime_error("Could not open file.");
  }

  std::string line;

  // Ignore the first line
  std::getline(file, line);

  // Read file word by word
  while (std::getline(file, line)) {
    try {
      // Split date and value
      std::size_t pos = line.find(" | ");
      if (pos == std::string::npos) {
        throw std::runtime_error("bad input => " + line);
      }

      std::string date = line.substr(0, pos);

      // Check if date is valid
      std::tm tm;

      char *p = strptime(date.c_str(), "%Y-%m-%d", &tm);
      if (p == NULL || *p != '\0') {
        throw std::runtime_error("bad date format => " + date);
      }

      // Get the price at the given date
      double price = this->getPrice(date);

      std::string value_str = line.substr(pos + 3);

      double value = std::strtod(value_str.c_str(), NULL);
      if (errno == ERANGE || value > 1000) {
        throw std::runtime_error("too large number.");
      } else if (value < 0) {
        throw std::runtime_error("not a positive number.");
      }

      std::cout << date << " => " << value << " = " << value * price
                << std::endl;
    } catch (const std::exception &e) {
      std::cerr << "Error: " << e.what() << std::endl;
    }
  }
}

double BitcoinExchange::getPrice(const std::string &date) {
  std::map<std::string, double>::const_iterator it = price_ot.lower_bound(date);
  if (it == price_ot.end()) {
    throw std::runtime_error("Date not found.");
  }

  return it->second;
}
