#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
private:
	std::string name;
public:
	Zombie( void );
	~Zombie();

	void setName( std::string name );
	void announce( void );
};

#endif /* ZOMBIE_HPP */
