#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
   private:
    static const int MATERIAS_INVENTORY = 4;
    AMateria *_learntMaterias[MATERIAS_INVENTORY];

   public:
    MateriaSource();
    MateriaSource(const MateriaSource &copy);
    ~MateriaSource();
    MateriaSource &operator=(const MateriaSource &copy);

    const std::string &getLearntMateria(int index) const;

    void learnMateria(AMateria *materia);
    AMateria *createMateria(const std::string &type);
};

#endif