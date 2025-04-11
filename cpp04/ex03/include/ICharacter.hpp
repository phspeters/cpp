#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include "AMateria.hpp"

class AMateria;

class ICharacter {
   public:
    virtual ~ICharacter() {};

    virtual const std::string& getName() const = 0;

    virtual void equip(AMateria* materia) = 0;
    virtual void unequip(int index) = 0;
    virtual void use(int index, ICharacter& target) = 0;
};

#endif