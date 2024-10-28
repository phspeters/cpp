#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character : public ICharacter {
public:
	Character();
	Character(std::string const &name);
	Character(Character const &copy);
	Character &operator=(Character const &copy);
	~Character();

	std::string const &getName() const;
	void equip(AMateria *materia);
	void unequip(int index);
	void use(int index, ICharacter &target);

private:
	static const int INVENTORY_SIZE = 4;
	std::string _name;
	AMateria *_inventory[INVENTORY_SIZE];
};

#endif