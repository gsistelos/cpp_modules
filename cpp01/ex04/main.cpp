#include <iostream>
#include <fstream>
#include <cstring>

static void replace( std::string& str, std::string const & s1, std::string const & s2 )
{
	if (s1.empty()) return ;

	for (size_t i = 0; (i = str.find(s1, i)) != std::string::npos; i += s2.length()) {
		str.erase(i, s1.length());
		str.insert(i, s2);
	}
}

int main( int argc, char** argv )
{
	if (argc != 4) {
		std::cerr << "Usage: ./Sed_is_for_losers [FILE] [FIND] [REPLACE]" << std::endl;
		return 1;
	}

	std::string fileName(argv[1]);

	std::ifstream infile(fileName.c_str());
	if (!infile.is_open()) {
		std::cerr << "Sed_is_for_losers: " << fileName <<  ": " << strerror(errno) << std::endl;
		return 1;
	}

	fileName += ".replace";
	std::ofstream outfile(fileName.c_str());
	if (!outfile.is_open()) {
		std::cerr << "Sed_is_for_losers: " << fileName <<  ": " << strerror(errno) << std::endl;
		infile.close();
		return 1;
	}

	std::string buffer;
	while (!infile.eof()) {
		std::getline(infile, buffer, '\0');

		replace(buffer, argv[2], argv[3]);

		outfile << buffer;
	}

	infile.close();
	outfile.close();
	return 0;
}
