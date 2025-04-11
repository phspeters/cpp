#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

void compareLearntMaterias(MateriaSource& src, MateriaSource& dst) {
    std::cout << "Comparing learnt materias of 'src' and 'dst'\n";
    for (int i = 0; i < 4; i++) {
        std::cout << "src: " << i << " " << src.getLearntMateria(i) << "\t|\t";
        std::cout << "dst: " << i << " " << dst.getLearntMateria(i) << '\n';
    }
}

void compareInventories(Character& first, Character& second) {
    std::cout << "Comparing inventories of " << first.getName() << " and "
              << second.getName() << '\n';
    for (int i = 0; i < 4; i++) {
        std::cout << first.getName() << ": " << i << " "
                  << first.getInventoryItem(i) << "\t|\t";
        std::cout << second.getName() << ": " << i << " "
                  << second.getInventoryItem(i) << '\n';
    }
}

void testMateriaSource() {
    std::cout << "TESTING MATERIASOURCE IMPLEMENTATION\n";
    MateriaSource src;
    MateriaSource dst;

    src.learnMateria(new Ice());
    src.learnMateria(new Cure());
    src.learnMateria(new Cure());
    src.learnMateria(new Ice());
    std::cout << '\n';

    std::cout << "Learning fifth materia in order to test limit\n";
    src.learnMateria(new Cure());
    std::cout << '\n';

    std::cout << "Creating new 'ice' materia\n";
    AMateria* tmp;
    tmp = src.createMateria("ice");
    std::cout << "Materia type: " << tmp->getType() << '\n';
    delete tmp;
    std::cout << "Creating new 'cure' materia\n";
    tmp = src.createMateria("cure");
    std::cout << "Materia type: " << tmp->getType() << '\n';
    delete tmp;
    std::cout << "Creating new 'unknown' materia\n";
    tmp = src.createMateria("unknown");
    std::cout << '\n';

    std::cout << "TESTING MATERIASOURCE DEEP COPY\n";

    compareLearntMaterias(src, dst);
    std::cout << '\n';

    std::cout << "Assigning 'src' to 'dst'\n";
    dst = src;
    std::cout << '\n';

    compareLearntMaterias(src, dst);
    std::cout << '\n';
}

void testCharacter() {
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    std::cout << '\n';

    std::cout << "TESTING CHARACTER IMPLEMENTATION\n";
    Character andy("andy");
    Character bob("bob");

    std::cout << "Equipping materias 'ice' and 'cure'\n";
    AMateria* tmp;
    tmp = src->createMateria("ice");
    andy.equip(tmp);
    tmp = src->createMateria("cure");
    andy.equip(tmp);
    std::cout << '\n';

    std::cout << "Using materias\n";
    andy.use(0, bob);
    andy.use(1, bob);
    andy.use(2, bob);
    std::cout << '\n';

    std::cout
        << "Equipping 3 other materias in order to test inventory limit\n";
    tmp = src->createMateria("ice");
    andy.equip(tmp);
    tmp = src->createMateria("cure");
    andy.equip(tmp);
    tmp = src->createMateria("ice");
    andy.equip(tmp);
    std::cout << '\n';

    std::cout << "Unequipping first materia\n";
    andy.unequip(0);

    std::cout << "Displaying inventory\n";
    std::cout << "Slot 0: " << andy.getInventoryItem(0) << '\n';
    std::cout << "Slot 1: " << andy.getInventoryItem(1) << '\n';
    std::cout << "Slot 2: " << andy.getInventoryItem(2) << '\n';
    std::cout << "Slot 3: " << andy.getInventoryItem(3) << '\n';
    std::cout << '\n';

    std::cout << "TESTING CHARACTER DEEP COPY\n";
    compareInventories(andy, bob);
    std::cout << '\n';

    std::cout << "Assigning 'andy' to 'bob'\n";
    bob = andy;

    compareInventories(andy, bob);
    std::cout << '\n';

    std::cout << "Unequipping third materia from 'andy', former 'bob'\n";
    bob.unequip(3);
    std::cout << '\n';

    compareInventories(andy, bob);
    std::cout << '\n';

    delete src;
}

void testBasePointers() {
    std::cout << "TESTING CLASSES IMPLEMENTATION AS BASE POINTERS\n";
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(NULL);
    std::cout << '\n';

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("fire");
    me->equip(tmp);
    std::cout << '\n';

    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob);
    std::cout << '\n';

    me->unequip(0);
    me->use(0, *bob);
    me->use(1, *bob);
    me->unequip(0);
    std::cout << '\n';

    delete bob;
    delete me;
    delete src;
}

int main() {
    testMateriaSource();
    std::cout << "-------------------------------------------------------------"
                 "-------------------\n\n";
    testCharacter();
    std::cout << "-------------------------------------------------------------"
                 "-------------------\n\n";
    testBasePointers();

    return 0;
}