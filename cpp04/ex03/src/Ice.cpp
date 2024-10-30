#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(Ice const &copy) : AMateria(copy) {}

Ice &Ice::operator=(Ice const &copy) {
	if (this != &copy) {
		AMateria::operator=(copy);
	}
	return (*this);
}

Ice::~Ice() {}

AMateria *Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
