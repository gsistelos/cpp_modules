#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
	std::string _name;
	AMateria* _inventory[4];
public:
	Character( void );
	Character( std::string const & name );
	Character( Character const & other );

	~Character();

	Character& operator=( Character const & other );

	std::string const & getName( void ) const;
	void equip( AMateria* m );
	void unequip( int idx );
	void use( int idx, ICharacter& target );
};

#endif /* CHARACTER_HPP */
