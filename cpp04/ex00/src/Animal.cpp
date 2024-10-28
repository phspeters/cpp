#include "Animal.hpp"

Animal::Animal() : _type("Animal") {
	std::cout << "Animal default constructor\n";
}

Animal::Animal(const Animal &copy) : _type(copy._type) {
	std::cout << "Animal copy constructor\n";
}

Animal &Animal::operator=(const Animal &copy) {
	if (this != &copy) {
		_type = copy._type;
	}

	std::cout << "Animal assignment operator\n";

	return (*this);
}

Animal::~Animal() {
	std::cout << "Animal destructor\n";
}

std::string Animal::getType() const {
	return (_type);
}

void Animal::makeSound() const {
	std::cout << "*Animal noises*\n";
}
