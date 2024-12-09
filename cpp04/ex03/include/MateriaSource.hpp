#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
private:
	static const int MATERIAS_INVENTORY = 4;
	AMateria *_learntMaterias[MATERIAS_INVENTORY];

public:
	MateriaSource();
	MateriaSource(MateriaSource const &copy);
	~MateriaSource();
	MateriaSource &operator=(MateriaSource const &copy);

	std::string const &getLearntMateria(int index) const;

	void learnMateria(AMateria *materia);
	AMateria *createMateria(std::string const &type);
};

#endif