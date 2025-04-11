#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
   public:
    // constructors
    Cat();
    Cat(const Cat& copy);

    // assignment operator
    Cat& operator=(const Cat& copy);

    // destructor
    ~Cat();

    // member functions
    void makeSound() const;
};

#endif