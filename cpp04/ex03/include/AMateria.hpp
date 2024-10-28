#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class AMateria {
public:
	AMateria();
	AMateria(std::string const &type);
	AMateria(AMateria const &copy);
	AMateria &operator=(AMateria const &copy);
	virtual ~AMateria();

	std::string const &getType() const;
	virtual void use(ICharacter &target);
	virtual AMateria *clone() const = 0;

protected:
	std::string _type;
};

#endif