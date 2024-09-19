#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	static int const MAX_MATERIAS = 4;
	AMateria *_learntMaterias[MAX_MATERIAS];

public:
	MateriaSource();
	MateriaSource(MateriaSource const &copy);
	~MateriaSource();
	MateriaSource &operator=(MateriaSource const &copy);

	void learnMateria(AMateria *materia);
	AMateria *createMateria(std::string const &type);
};

#endif