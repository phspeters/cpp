#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;

	std::cout << "ScavTrap " << _name << " has been constructed by default!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;

	std::cout << "ScavTrap " << _name << " has been constructed!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavtrap) : ClapTrap(scavtrap)
{
	std::cout << "ScavTrap " << _name << " has been copy constructed!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavtrap)
{
	if (this != &scavtrap)
	{
		ClapTrap::operator=(scavtrap);
	}

	std::cout << "ScavTrap has been assigned the attributes of " << _name << std::endl;

	return *this;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << _name << " has been destroyed!" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (_hitPoints == 0)
	{
		std::cout << "ScavTrap " << _name << " is already dead and can't attack!" << std::endl;
		return ;
	}

	if (_energyPoints == 0)
	{
		std::cout << "ScavTrap " << _name << " is out of energy points and can't attack!" << std::endl;
		return ;
	}

	_energyPoints--;

	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate(void)
{
	if (_hitPoints == 0)
	{
		std::cout << "ScavTrap " << _name << " is already dead and can't guard the gate!" << std::endl;
		return ;
	}

	if(_energyPoints == 0)
	{
		std::cout << "ScavTrap " << _name << " is out of energy points and can't guard the gate!" << std::endl;
		return ;
	}

	_energyPoints--;
	
	std::cout << "Careful! ScavTrap " << _name << " is now guarding the gate!" << std::endl;
}
