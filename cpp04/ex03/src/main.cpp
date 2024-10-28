#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int	main() {
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter *me = new Character("me");

	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter *bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);

	src->learnMateria(new Cure());
	src->learnMateria(new Ice());

	bob->equip(tmp);
	tmp = src->createMateria("ice");
	bob->equip(tmp);
	bob->equip(tmp);
	bob->equip(tmp);

	bob->use(0, *bob);
	bob->use(1, *me);
	bob->use(2, *me);
	bob->use(3, *me);
	bob->use(4, *me);

	me->unequip(0);
	me->unequip(1);
	me->unequip(2);

	bob->unequip(0);
	bob->unequip(1);
	bob->unequip(2);
	bob->unequip(3);

	delete bob;
	delete me;
	delete src;

	return (0);
}