#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

#include "ICharacter.hpp"

class ICharacter;

class AMateria {
   public:
    AMateria();
    AMateria(const std::string& type);
    AMateria(const AMateria& copy);
    AMateria& operator=(const AMateria& copy);
    virtual ~AMateria();

    const std::string& getType() const;
    virtual void use(ICharacter& target);
    virtual AMateria* clone() const = 0;

   protected:
    std::string _type;
};

#endif