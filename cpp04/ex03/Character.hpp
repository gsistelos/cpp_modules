#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
	std::string name;
	AMateria *inventory[4];
public:
	Character(void);
	Character(std::string& name);
	~Character();

	ICharacter& operator=(ICharacter& other);

	std::string const & getName();
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};

#endif /* CHARACTER_HPP */
