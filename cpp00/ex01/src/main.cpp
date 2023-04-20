#include "main.hpp"

int main(void)
{
	PhoneBook phonebook;
	std::string input;
	while (!std::cin.eof()) {
		prompt(input);
		if (input == "ADD")
			phonebook.add();
		else if (input == "SEARCH")
			phonebook.search();
		else if (input == "EXIT")
			break ;
		else
			std::cout << "Invalid action" << std::endl;
	}
	return 0;
}
