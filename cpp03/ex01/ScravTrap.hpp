#ifndef SCRAVTRAP_HPP
#define SCRAVTRAP_HPP

#include "ClapTrap.hpp"

class ScravTrap: public ClapTrap {
private:
	std::string name;
public:
	ScravTrap( std::string name);
	~ScravTrap();
};

#endif //SCRAVTRAP_HPP
