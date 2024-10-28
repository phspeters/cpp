#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
private:
	static int const MATERIAS_INVENTORY = 4;
	AMateria *_learntMaterias[MATERIAS_INVENTORY];
	static int const MAX_MATERIAS = 50;
	AMateria *_createdMaterias[MAX_MATERIAS];

public:
	MateriaSource();
	MateriaSource(MateriaSource const &copy);
	~MateriaSource();
	MateriaSource &operator=(MateriaSource const &copy);

	void learnMateria(AMateria *materia);
	AMateria *createMateria(std::string const &type);

	void manageMaterias(AMateria *materia);
};

#endif