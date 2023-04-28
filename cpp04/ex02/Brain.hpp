#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
private:
	std::string ideas[100];
public:
	Brain(void);
	Brain(const Brain &other);
	~Brain();

	Brain &operator=(const Brain &other);
};

#endif /* BRAIN_HPP */
