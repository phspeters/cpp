#include "Cat.hpp"

Cat::Cat() : Animal() {
	_type = "Cat";
	_brain = new Brain();

	std::cout << "Cat default constructor\n";
}

Cat::Cat(const Cat &copy) : Animal(), _brain(NULL) {
	*this = copy;

	std::cout << "Cat copy constructor\n";
}

Cat &Cat::operator=(const Cat &copy) {
	if (this != &copy) {
		Animal::operator=(copy);

		if (_brain) {
			delete _brain;
		}
		_brain = new Brain(*copy._brain);
	}

	std::cout << "Cat assignment operator\n";

	return (*this);
}

Cat::~Cat() {
	delete _brain;
	
	std::cout << "Cat destructor\n";
}

void Cat::makeSound() const {
	std::cout << "Meow meow\n";
}

Brain *Cat::getBrain() const {
	return (_brain);
}
