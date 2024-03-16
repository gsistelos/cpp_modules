#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]) {
  (void)argc;

  BitcoinExchange exchanger;

  exchanger.parseData("data.csv");
  exchanger.exchange(argv[1]);

  return 0;
}
