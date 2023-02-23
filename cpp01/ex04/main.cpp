#include <iostream>
#include <fstream>
#include <cstring>

#define BUFFER_SIZE 1024

static std::string replace(const std::string& str, const std::string& s1, const std::string& s2) {
	std::string new_str;
	size_t pos = 0;
	size_t found;
	while ((found = str.find(s1, pos)) != std::string::npos) {
		new_str += str.substr(pos, found - pos);
		new_str += s2;
		pos = found + s1.length();
	}
	new_str += str.substr(pos);
	return new_str;
}

int main(int argc, char **argv) {
	if (argc != 4) {
		std::cerr << "Usage: ./Sed_is_for_losers [FILE] [FIND] [REPLACE]" << std::endl;
		return 1;
	}

	std::string file = argv[1];

	std::ifstream infile;
	infile.open(file.c_str());
	if (!infile.is_open()) {
		std::cerr << "Sed_is_for_losers: " << file <<  ": " << strerror(errno) << std::endl;
		return 1;
	}

	file += ".replace";
	std::ofstream outfile;
	outfile.open(file.c_str());
	if (!outfile.is_open()) {
		std::cerr << "Sed_is_for_losers: " << file <<  ": " << strerror(errno) << std::endl;
		infile.close();
		return 1;
	}

	char buffer[BUFFER_SIZE];
	while (!infile.eof()) {
		infile.read(&buffer[0], BUFFER_SIZE);
		buffer[infile.gcount()] = '\0';
		outfile << replace(buffer, argv[2], argv[3]);
	}
	infile.close();
	outfile.close();
	return 0;
}
