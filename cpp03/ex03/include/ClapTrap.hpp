#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
public:
	//constructors
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &claptrap);

	//assignment operator
	ClapTrap &operator=(const ClapTrap &claptrap);

	//destructor
	~ClapTrap(void);

	//member functions
	void	attack(const std::string &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	//getters
	std::string		getName(void) const;
	unsigned int	getHitPoints(void) const;
	unsigned int	getEnergyPoints(void) const;
	unsigned int	getAttackDamage(void) const;

	//setters
	void	setHitPoints(unsigned int hitPoints);
	void	setEnergyPoints(unsigned int energyPoints);

protected:
	//member attributes
	std::string		_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;
};

#endif