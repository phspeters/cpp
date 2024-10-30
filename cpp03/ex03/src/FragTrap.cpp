#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap() {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;

	std::cout << "FragTrap " << _name << " has been constructed by default!\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;

	std::cout << "FragTrap " << _name << " has been constructed!\n";
}

FragTrap::FragTrap(const FragTrap &fragtrap) : ClapTrap(fragtrap) {
	std::cout << "FragTrap " << _name << " has been copy constructed!\n";
}

FragTrap &FragTrap::operator=(const FragTrap &fragtrap) {
	std::string oldName = _name;

	if (this != &fragtrap) {
		ClapTrap::operator=(fragtrap);
	}
	
	if (oldName != "") {
		std::cout << "FragTrap "<< oldName << " has been assigned the attributes of " << _name << '\n';
	}
	else {
		std::cout << "FragTrap has been assigned the attributes of " << _name << '\n';
	}
	
	return (*this);
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap " << _name << " has been destroyed!\n";
}

void FragTrap::highFivesGuys(void) {
	if (_hitPoints == 0) {
		std::cout << "FragTrap " << _name << " is already dead and can't request for high fives!\n";
		return ;
	}

	if(_energyPoints == 0) {
		std::cout << "FragTrap " << _name << " is out of energy points and can't request for high fives!\n";
		return ;
	}

	_energyPoints--;
	
	std::cout << "FragTrap " << _name << " requests a high five!\n";
}
