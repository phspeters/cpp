#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;

	std::cout << "DiamondTrap " << _name << " has been constructed!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondtrap) : ClapTrap(diamondtrap._name + "_clap_name"), ScavTrap(diamondtrap), FragTrap(diamondtrap), _name(diamondtrap._name)
{
	std::cout << "DiamondTrap " << _name << " has been copy constructed!" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamondtrap)
{
	if (this != &diamondtrap)
	{
		ClapTrap::operator=(diamondtrap);
		_name = diamondtrap._name;
	}

	std::cout << "DiamondTrap has had its attributes assigned from " << _name << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << _name << " has been destroyed!" << std::endl;
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap " << _name << " is also known as ClapTrap " << ClapTrap::_name << std::endl;
}
