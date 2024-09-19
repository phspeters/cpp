#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < MAX_MATERIAS; i++)
		_learntMaterias[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &copy)
{
	for (int i = 0; i < MAX_MATERIAS; i++)
		_learntMaterias[i] = copy._learntMaterias[i]->clone();
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < MAX_MATERIAS; i++)
		delete _learntMaterias[i];
}

MateriaSource &MateriaSource::operator=(MateriaSource const &copy)
{
	if (this != &copy)
	{
		for (int i = 0; i < MAX_MATERIAS; i++)
			delete _learntMaterias[i];
		for (int i = 0; i < MAX_MATERIAS; i++)
			_learntMaterias[i] = copy._learntMaterias[i]->clone();
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *materia)
{
	for (int i = 0; i < MAX_MATERIAS; i++)
	{
		if (!_learntMaterias[i])
		{
			_learntMaterias[i] = materia->clone();
			break;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < MAX_MATERIAS; i++)
	{
		if (_learntMaterias[i] && _learntMaterias[i]->getType() == type)
		{
			AMateria *newMateria = _learntMaterias[i]->clone();
			//
			return (newMateria);
		}
	}
	return (NULL);
}
