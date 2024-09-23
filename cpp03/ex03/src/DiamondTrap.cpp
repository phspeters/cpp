#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap(), ScavTrap(), FragTrap(), _name("nameless")
{
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;

	std::cout << "DiamondTrap " << _name << " has been constructed by default!\n";
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;

	std::cout << "DiamondTrap " << _name << " has been constructed!\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondtrap) : ClapTrap(diamondtrap._name + "_clap_name"), ScavTrap(diamondtrap), FragTrap(diamondtrap), _name(diamondtrap._name)
{
	std::cout << "DiamondTrap " << _name << " has been copy constructed!\n";
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamondtrap)
{
	if (this != &diamondtrap)
	{
		ClapTrap::operator=(diamondtrap);
		_name = diamondtrap._name;
	}

	std::cout << "DiamondTrap has been assigned the attributes of " << _name << '\n';
	
	return *this;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << _name << " has been destroyed!\n";
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap " << getName() << " is also known as ClapTrap " << ClapTrap::getName() << '\n';
}

std::string DiamondTrap::getName(void)
{
	return _name;
}
