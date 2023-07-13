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

	std::string randomIdea(void) const;
};

#endif /* BRAIN_HPP */
