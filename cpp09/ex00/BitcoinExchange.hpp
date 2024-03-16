#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
public:
  BitcoinExchange(void);
  BitcoinExchange(const BitcoinExchange &rhs);
  BitcoinExchange &operator=(const BitcoinExchange &rhs);
  ~BitcoinExchange();

  void parseData(const std::string &filename);
  void exchange(const std::string &filename) const;

  void printExchangeRates(void) const;

private:
  std::map<std::string, double> _exchangeRates;
};

#endif // BITCOINEXCHANGE_HPP
