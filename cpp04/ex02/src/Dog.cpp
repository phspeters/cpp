#include "Dog.hpp"

Dog::Dog() : Animal() {
	_type = "Dog";
	_brain = new Brain();

	std::cout << "Dog default constructor\n";
}

Dog::Dog(const Dog &copy) : Animal(), _brain(NULL) {
	*this = copy;

	std::cout << "Dog copy constructor\n";
}

Dog &Dog::operator=(const Dog &copy) {
	if (this != &copy) {
		Animal::operator=(copy);
		if (_brain) {
			delete _brain;
		}
		_brain = new Brain(*copy._brain);
	}

	std::cout << "Dog assignment operator\n";

	return (*this);
}

Dog::~Dog() {
	delete _brain;
	
	std::cout << "Dog destructor\n";
}

void Dog::makeSound() const {
	std::cout << "Woof woof\n";
}

Brain *Dog::getBrain() const {
	return (_brain);
}
