#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
    return 1;
  }

  try {
    BitcoinExchange bitcoin_exchange;

    bitcoin_exchange.exchange(argv[1]);
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  return 0;
}
