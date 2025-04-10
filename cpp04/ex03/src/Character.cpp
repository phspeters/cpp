#include "Character.hpp"

Character::Character() : _name("nameless") {
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        _inventory[i] = NULL;
    }

    for (int i = 0; i < DROPPED_SIZE; i++) {
        _droppedMateria[i] = NULL;
    }
}

Character::Character(const std::string& name) : _name(name) {
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        _inventory[i] = NULL;
    }

    for (int i = 0; i < DROPPED_SIZE; i++) {
        _droppedMateria[i] = NULL;
    }
}

Character::Character(const Character& copy) { *this = copy; }

Character& Character::operator=(const Character& copy) {
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

    return *this;
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

const std::string& Character::getName() const { return _name; }

const std::string& Character::getInventoryItem(int index) const {
    if (_inventory[index]) {
        return (_inventory[index]->getType());
    } else {
        static const std::string empty = "empty";
        return empty;
    }
}

void Character::equip(AMateria* materia) {
    if (!materia) {
        std::cerr << _name << ": could not equip materia, materia is unknown\n";
        return;
    }

    for (int i = 0; i < INVENTORY_SIZE; i++) {
        if (!_inventory[i]) {
            _inventory[i] = materia;
            std::cout << _name << ": equipped '" << materia->getType()
                      << "' materia in slot " << i << '\n';
            return;
        }
    }

    std::cerr << _name << ": could not equip materia, my inventory is full\n";
    delete materia;
    materia = NULL;
}

void Character::unequip(int index) {
    if (index < 0 || index >= INVENTORY_SIZE) {
        return;
    }

    if (!_inventory[index]) {
        std::cerr << _name << ": could not unequip materia, slot " << index
                  << " is already empty\n";
        return;
    }

    for (int i = 0; i < DROPPED_SIZE; i++) {
        if (!_droppedMateria[i]) {
            _droppedMateria[i] = _inventory[index];
            break;
        }
        if (i == DROPPED_SIZE - 1) {
            std::cerr << _name
                      << ": could not unequip materia, floor is already full "
                         "of materias\n";
            return;
        }
    }

    std::cout << _name << ": unequipped '" << _inventory[index]->getType()
              << "' materia from slot " << index << '\n';
    _inventory[index] = NULL;
}

void Character::use(int index, ICharacter& target) {
    if (index < 0 || index >= INVENTORY_SIZE) {
        return;
    }

    if (!_inventory[index]) {
        std::cerr << _name << ": could not use materia, slot " << index
                  << " is empty\n";
        return;
    }

    std::cout << _name << ": ";
    _inventory[index]->use(target);
}
