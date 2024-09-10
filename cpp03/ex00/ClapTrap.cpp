#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " has been constructed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;

	std::cout << "ClapTrap " << _name << " has been copy constructed!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;

	std::cout << "ClapTrap " << _name << " has had its attributes assigned!" << std::endl;

	return *this;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << _name << " has been destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is out of energy points and can't attack!" << std::endl;
		return ;
	}

	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is dead and can't attack!" << std::endl;
		return ;
	}

	_energyPoints -= 1;
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
		return ;
	}

	if (amount > _hitPoints)
	{
		amount = _hitPoints;
	}

	_hitPoints -= amount;
	std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is out of energy points and can't be repaired!" << std::endl;
		return ;
	}

	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is already dead and can't be repaired!" << std::endl;
		return ;
	}

	if (_hitPoints == 10)
	{
		std::cout << "ClapTrap " << _name << " is already at full hitpoints and can't be repaired further!" << std::endl;
		return ;
	}

	_hitPoints += amount;
	if (_hitPoints > 10)
	{
		_hitPoints = 10;
	}

	_energyPoints -= 1;
	std::cout << "ClapTrap " << _name << " is repaired for " << amount << " points!" << std::endl;
}

std::string ClapTrap::getName(void) const
{
	return _name;
}

unsigned int ClapTrap::getHitPoints(void) const
{
	return _hitPoints;
}

unsigned int ClapTrap::getEnergyPoints(void) const
{
	return _energyPoints;
}

unsigned int ClapTrap::getAttackDamage(void) const
{
	return _attackDamage;
}

void ClapTrap::setHitPoints(unsigned int hitPoints)
{
	_hitPoints = hitPoints;

	std::cout << "ClapTrap " << _name << " has had its hitpoints artificially set to " << hitPoints << "!" << std::endl;
}

void ClapTrap::setEnergyPoints(unsigned int energyPoints)
{
	_energyPoints = energyPoints;

	std::cout << "ClapTrap " << _name << " has had its energy points artificially set to " << energyPoints << "!" << std::endl;
}
