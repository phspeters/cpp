#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < MATERIAS_INVENTORY; i++) {
        _learntMaterias[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource& copy) { *this = copy; }

MateriaSource::~MateriaSource() {
    for (int i = 0; i < MATERIAS_INVENTORY; i++) {
        if (_learntMaterias[i]) {
            delete _learntMaterias[i];
            _learntMaterias[i] = NULL;
        }
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& copy) {
    if (this != &copy) {
        for (int i = 0; i < MATERIAS_INVENTORY; i++) {
            if (_learntMaterias[i]) {
                delete _learntMaterias[i];
                _learntMaterias[i] = NULL;
            }

            if (copy._learntMaterias[i]) {
                _learntMaterias[i] = copy._learntMaterias[i]->clone();
            }
        }
    }

    return *this;
}

const std::string& MateriaSource::getLearntMateria(int index) const {
    if (_learntMaterias[index]) {
        return (_learntMaterias[index]->getType());
    } else {
        static const std::string empty = "empty";
        return empty;
    }
}

void MateriaSource::learnMateria(AMateria* materia) {
    if (!materia) {
        std::cerr << "MateriaSource: cannot learn invalid materia\n";
        return;
    }

    for (int i = 0; i < MATERIAS_INVENTORY; i++) {
        if (!_learntMaterias[i]) {
            _learntMaterias[i] = materia;
            std::cout << "MateriaSource: learnt new materia of type '"
                      << materia->getType() << "' on slot " << i << '\n';
            break;
        }

        if (i == 3) {
            std::cerr << "MateriaSource: no free slots to learn new materia\n";
            delete materia;
        }
    }
}

AMateria* MateriaSource::createMateria(const std::string& type) {
    for (int i = 0; i < MATERIAS_INVENTORY; i++) {
        if (_learntMaterias[i] && _learntMaterias[i]->getType() == type) {
            AMateria* newMateria = _learntMaterias[i]->clone();
            return newMateria;
        }
    }

    std::cerr << "MateriaSource: could not create materia of type '" << type
              << "': type not found\n";

    return NULL;
}
