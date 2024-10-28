#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap() {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	
	std::cout << "ScavTrap " << _name << " has been constructed by default!\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;

	std::cout << "ScavTrap " << _name << " has been constructed!\n";
}

ScavTrap::ScavTrap(const ScavTrap &scavtrap) : ClapTrap(scavtrap) {
	std::cout << "ScavTrap " << _name << " has been copy constructed!\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavtrap) {
	std::string oldName = _name;

	if (this != &scavtrap) {
		ClapTrap::operator=(scavtrap);
	}
	
	if (oldName != "") {
		std::cout << "ScavTrap "<< oldName << " has been assigned the attributes of " << _name << '\n';
	}
	else {
		std::cout << "ScavTrap has been assigned the attributes of " << _name << '\n';
	}
	
	return *this;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap " << _name << " has been destroyed!\n";
}

void ScavTrap::attack(const std::string &target) {
	if (_hitPoints == 0) {
		std::cout << "ScavTrap " << _name << " is already dead and can't attack!\n";
		return ;
	}

	if (_energyPoints == 0) {
		std::cout << "ScavTrap " << _name << " is out of energy points and can't attack!\n";
		return ;
	}

	_energyPoints--;

	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!\n";
}

void ScavTrap::guardGate(void) {
	if (_hitPoints == 0) {
		std::cout << "ScavTrap " << _name << " is already dead and can't guard the gate!\n";
		return ;
	}

	if (_energyPoints == 0) {
		std::cout << "ScavTrap " << _name << " is out of energy points and can't guard the gate!\n";
		return ;
	}

	_energyPoints--;
	
	std::cout << "Careful! ScavTrap " << _name << " is now guarding the gate!\n";
}
