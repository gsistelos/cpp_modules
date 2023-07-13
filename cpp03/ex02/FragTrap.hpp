#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap( void );
	FragTrap( std::string const & name );
	FragTrap( FragTrap const & other );
	~FragTrap();

	FragTrap& operator=( FragTrap const & other );

	void highFiveGuys( void );
};

#endif /* FRAGTRAP_HPP */
