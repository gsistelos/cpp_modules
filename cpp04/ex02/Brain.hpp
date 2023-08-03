#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{
private:
	std::string ideas[100];

public:
	Brain( void );
	Brain( Brain const & other );
	~Brain();

	Brain &operator=( Brain const & other );
};

#endif /* BRAIN_HPP */
