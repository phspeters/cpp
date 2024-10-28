#include "Cat.hpp"

Cat::Cat() : Animal() {
	_type = "Cat";
	
	std::cout << "Cat default constructor\n";
}

Cat::Cat(const Cat &copy) : Animal(copy) {
	std::cout << "Cat copy constructor\n";
}

Cat &Cat::operator=(const Cat &copy) {
	if (this != &copy) {
		Animal::operator=(copy);
	}

	std::cout << "Cat assignment operator\n";

	return (*this);
}

Cat::~Cat() {
	std::cout << "Cat destructor\n";
}

void Cat::makeSound() const {
	std::cout << "Meow meow\n";
}
