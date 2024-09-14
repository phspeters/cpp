#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
public:
	//constructors
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap &diamondtrap);

	//assignment operator
	DiamondTrap &operator=(const DiamondTrap &diamondtrap);

	//destructor
	~DiamondTrap(void);

	//member functions
	void		whoAmI(void);
	std::string	getName(void);
	
private:
	std::string _name;
};

#endif