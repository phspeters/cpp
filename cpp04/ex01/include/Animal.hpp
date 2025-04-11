#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
   public:
    // constructors
    Animal();
    Animal(const Animal& copy);

    // assignment operator
    Animal& operator=(const Animal& copy);

    // destructor
    virtual ~Animal();

    // member functions
    std::string getType() const;
    virtual void makeSound() const;

   protected:
    std::string _type;
};

#endif