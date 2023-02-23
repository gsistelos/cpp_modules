#include <iostream>

void prompt(std::string& input) {
	std::cout << "|  ADD |  SEARCH  | EXIT |" << std::endl;
	std::cout << ">";
	std::getline(std::cin, input);
}

void input(const std::string& output, std::string& buffer) {
	std::cout << output;
	std::getline(std::cin, buffer);
	while (!std::cin.eof() && buffer.empty()) {
		std::cout << "Invalid input: empty line" << std::endl;
		std::cout << output;
		std::getline(std::cin, buffer);
	}
}

std::string shrink(const std::string& str) {
	std::string sub = str.substr(0, 10);
	if (sub.length() == 10)
		sub[9] = '.';
	return sub;
}
