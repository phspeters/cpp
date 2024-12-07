#include "Character.hpp"

Character::Character() : _name("default") {
	for (int i = 0; i < INVENTORY_SIZE; i++) {
		_inventory[i] = NULL;
	}

	for (int i = 0; i < DROPPED_SIZE; i++) {
		_droppedMateria[i] = NULL;
	}
}

Character::Character(std::string const &name) : _name(name) {
	for (int i = 0; i < INVENTORY_SIZE; i++) {
		_inventory[i] = NULL;
	}

	for (int i = 0; i < DROPPED_SIZE; i++) {
		_droppedMateria[i] = NULL;
	}
}

Character::Character(Character const &copy) {
	*this = copy;
}

Character &Character::operator=(Character const &copy) {
	_name = copy._name;

	for (int i = 0; i < INVENTORY_SIZE; i++) {
		if (_inventory[i]) {
			delete _inventory[i];
			_inventory[i] = NULL;
		}
		
		if (copy._inventory[i]) {
			_inventory[i] = copy._inventory[i]->clone();
		}
	}

	return (*this);
}

Character::~Character() {
	for (int i = 0; i < INVENTORY_SIZE; i++) {
		if (_inventory[i]) {
			delete _inventory[i];
			_inventory[i] = NULL;
		}
	}

	for (int i = 0; i < DROPPED_SIZE; i++) {
		if (_droppedMateria[i]) {
			delete _droppedMateria[i];
			_droppedMateria[i] = NULL;
		}
	}
}

std::string const &Character::getName() const {
	return (_name);
}

void Character::displayInventory() const {
	for (int i = 0; i < INVENTORY_SIZE; i++) {
		if (_inventory[i]) {
			std::cout << "Slot " << i << ": " << _inventory[i]->getType() << '\n';
		}
		else {
			std::cout << "Slot " << i << ": empty\n";
		}
	}
	std::cout << '\n';
}

void Character::equip(AMateria *materia) {
	if (!materia) {
		std::cerr << "Character: Could not equip materia: materia pointer is invalid\n";
		return ;
	}

	for (int i = 0; i < INVENTORY_SIZE; i++) {
		if (!_inventory[i]) {
			_inventory[i] = materia;
			std::cout << "Character: " << _name << " equipped " << materia->getType() << " materia on slot " << i << '\n';
			return ;
		}
	}

	std::cerr << "Character: Could not equip materia: inventory is full\n";
}

void Character::unequip(int index) {
	if (index < 0 || index >= INVENTORY_SIZE || !_inventory[index]) {
		return ;
	}

	for (int i = 0; i < DROPPED_SIZE; i++) {
		if (!_droppedMateria[i]) {
			_droppedMateria[i] = _inventory[index];
			break;
		}
		if (i == DROPPED_SIZE - 1) {
			std::cerr << "Character: Could not unequip materia: dropped inventory is full\n";
		}
	}
	
	if (_inventory[index]) {
		std::cout << "Character: " << _name << " unequipped " << _inventory[index]->getType() << " materia from slot " << index << '\n';
		_inventory[index] = NULL;
	}
}

void Character::use(int index, ICharacter &target) {
	if (index < 0 || index >= INVENTORY_SIZE || !_inventory[index]) {
		return ;
	}

	_inventory[index]->use(target);
}
