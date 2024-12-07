#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < MATERIAS_INVENTORY; i++) {
		_learntMaterias[i] = NULL;
	}
}

MateriaSource::MateriaSource(MateriaSource const &copy) {
	for (int i = 0; i < MATERIAS_INVENTORY; i++) {
		if (copy._learntMaterias[i]) {
			_learntMaterias[i] = copy._learntMaterias[i]->clone();
		}
	}
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < MATERIAS_INVENTORY; i++) {
		if (_learntMaterias[i]) {
			delete _learntMaterias[i];
			_learntMaterias[i] = NULL;
		}
	}
}

MateriaSource &MateriaSource::operator=(MateriaSource const &copy) {
	if (this != &copy) {
		for (int i = 0; i < MATERIAS_INVENTORY; i++) {
			if (_learntMaterias[i]) {
				delete _learntMaterias[i];
				_learntMaterias[i] = NULL;
			}
		}

		for (int i = 0; i < MATERIAS_INVENTORY; i++) {
			if (copy._learntMaterias[i]) {
				_learntMaterias[i] = copy._learntMaterias[i]->clone();
			}
		}
	}

	return (*this);
}

void MateriaSource::learnMateria(AMateria *materia) {
	for (int i = 0; i < MATERIAS_INVENTORY; i++) {
		if (!_learntMaterias[i]) {
			_learntMaterias[i] = materia->clone();
			break;
		}

		if (i == 3) {
			std::cerr << "MateriaSource: No free slots to learn new materia\n";
			delete materia;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < MATERIAS_INVENTORY; i++) {
		if (_learntMaterias[i] && _learntMaterias[i]->getType() == type) {
			AMateria *newMateria = _learntMaterias[i]->clone();
			return (newMateria);
		}
	}

	std::cerr << "MateriaSource: Could not create materia of type " << type << ": type not found\n";

	return (NULL);
}
