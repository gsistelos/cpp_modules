#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
public:
  BitcoinExchange(void);
  BitcoinExchange(const BitcoinExchange &src);
  ~BitcoinExchange();

  BitcoinExchange &operator=(const BitcoinExchange &rhs);

  void exchange(const std::string &filename);

private:
  std::map<std::string, double> price_ot; // bitcoin price over time

  double getPrice(const std::string &date);
};

#endif
