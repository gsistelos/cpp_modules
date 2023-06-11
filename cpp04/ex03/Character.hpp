#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
	std::string _name;
	AMateria* _inventory[4];
public:
	Character( void );
	Character( std::string& name );
	Character( ICharacter const & other );

	~Character();

	Character& operator=( ICharacter const & other );

	std::string const & getName() const;
	void equip( AMateria* m );
	void unequip( int idx );
	void use( int idx, ICharacter& target );
};

#endif /* CHARACTER_HPP */
