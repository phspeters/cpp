#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter {
   public:
    Character();
    Character(const std::string &name);
    Character(const Character &copy);
    Character &operator=(const Character &copy);
    ~Character();

    const std::string &getName() const;
    const std::string &getInventoryItem(int index) const;

    void equip(AMateria *materia);
    void unequip(int index);
    void use(int index, ICharacter &target);

   private:
    std::string _name;
    static const int INVENTORY_SIZE = 4;
    AMateria *_inventory[INVENTORY_SIZE];
    static const int DROPPED_SIZE = 10;
    AMateria *_droppedMateria[DROPPED_SIZE];
};

#endif