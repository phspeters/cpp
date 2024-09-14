#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;

	std::cout << "FragTrap " << _name << " has been constructed by default!" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;

	std::cout << "FragTrap " << _name << " has been constructed!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &fragtrap) : ClapTrap(fragtrap)
{
	std::cout << "FragTrap " << _name << " has been copy constructed!" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &fragtrap)
{
	if (this != &fragtrap)
	{
		ClapTrap::operator=(fragtrap);
	}

	std::cout << "FragTrap has been assigned the attributes of " << _name << std::endl;
	
	return *this;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << _name << " has been destroyed!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	if (_hitPoints == 0)
	{
		std::cout << "FragTrap " << _name << " is already dead and can't request for high fives!" << std::endl;
		return ;
	}

	if(_energyPoints == 0)
	{
		std::cout << "FragTrap " << _name << " is out of energy points and can't request for high fives!" << std::endl;
		return ;
	}

	_energyPoints--;

	std::cout << "FragTrap " << _name << " is requesting high fives!" << std::endl;
}
