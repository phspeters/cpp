#include "AMateria.hpp"

AMateria::AMateria() : _type("unknown") {}

AMateria::AMateria(std::string const &type) : _type(type) {}

AMateria::AMateria(AMateria const &copy)
{
	*this = copy;
}

AMateria &AMateria::operator=(AMateria const &copy)
{
	if (this != &copy)
		_type = copy._type;
	return *this;
}

AMateria::~AMateria() {}

std::string const &AMateria::getType() const
{
	return _type;
}

void AMateria::use(ICharacter &target)
{
	std::cout << "* uses unknown materia on " << target.getName() << " *\n";
}
