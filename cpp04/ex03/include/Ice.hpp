#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice();
	Ice(Ice const &copy);
	~Ice();
	Ice &operator=(Ice const &copy);

	AMateria *clone() const;
	void use(ICharacter &target);
};

#endif