#include "Dog.hpp"

Dog::Dog() : Animal() {
    _type = "Dog";

    std::cout << "Dog default constructor\n";
}

Dog::Dog(const Dog& copy) : Animal(copy) {
    std::cout << "Dog copy constructor\n";
}

Dog& Dog::operator=(const Dog& copy) {
    if (this != &copy) {
        Animal::operator=(copy);
    }

    std::cout << "Dog assignment operator\n";

    return *this;
}

Dog::~Dog() { std::cout << "Dog destructor\n"; }

void Dog::makeSound() const { std::cout << "Woof woof\n"; }
