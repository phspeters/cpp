#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
    std::cout << "WrongAnimal constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy) {
    *this = copy;

    std::cout << "WrongAnimal copy constructor called\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& copy) {
    if (this != &copy) {
        _type = copy._type;
    }

    std::cout << "WrongAnimal assignment operator called\n";

    return *this;
}

WrongAnimal::~WrongAnimal() { std::cout << "WrongAnimal destructor called\n"; }

void WrongAnimal::makeSound() const { std::cout << "*sesion laminA*\n"; }

std::string WrongAnimal::getType() const { return _type; }
