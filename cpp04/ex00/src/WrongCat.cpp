#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	_type = "WrongCat";

	std::cout << "WrongCat constructor called\n";
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy) {
	*this = copy;

	std::cout << "WrongCat copy constructor called\n";
}

WrongCat &WrongCat::operator=(const WrongCat &copy) {
	if (this != &copy) {
		WrongAnimal::operator=(copy);
	}

	std::cout << "WrongCat assignment operator called\n";

	return (*this);
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called\n";
}

void WrongCat::makeSound() const {
	std::cout << "woem woeM\n";
}
