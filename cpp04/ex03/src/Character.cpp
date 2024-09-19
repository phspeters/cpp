#include "Character.hpp"

Character::Character() : _name("default"), _inventory() {}

Character::Character(std::string const &name) : _name(name), _inventory() {}

Character::Character(Character const &copy)
{
	*this = copy;
}

Character &Character::operator=(Character const &copy)
{
	_name = copy._name;
	for (int i = 0; i < INVENTORY_SIZE; i++)
	{
		delete _inventory[i];
		_inventory[i] = NULL;
		if (copy._inventory[i])
			_inventory[i] = copy._inventory[i]->clone();
	}
	return *this;
}

Character::~Character() {}

std::string const &Character::getName() const
{
	return _name;
}

void Character::equip(AMateria *materia)
{
	for (int i = 0; i < INVENTORY_SIZE; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = materia;
			return;
		}
	}
}

void Character::unequip(int index)
{
	if (index < 0 || index >= INVENTORY_SIZE || !_inventory[index])
		return;
	_inventory[index] = NULL;
}

void Character::use(int index, ICharacter &target)
{
	if (index < 0 || index >= INVENTORY_SIZE || !_inventory[index])
		return;
	_inventory[index]->use(target);
}
