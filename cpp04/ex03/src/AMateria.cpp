#include "AMateria.hpp"

AMateria::AMateria() : _type("unknown") {}

AMateria::AMateria(const std::string& type) : _type(type) {}

AMateria::AMateria(const AMateria& copy) { *this = copy; }

AMateria& AMateria::operator=(const AMateria& copy) {
    if (this != &copy) {
        _type = copy._type;
    }

    return *this;
}

AMateria::~AMateria() {}

const std::string& AMateria::getType() const { return _type; }

void AMateria::use(ICharacter& target) {
    std::cout << "* uses unknown materia on " << target.getName() << " *\n";
}
