#include "DiamondTrap.hpp"

int	main(void)
{
	std::cout << "Testing constructors, assignment operator and destructor:" << std::endl;
	DiamondTrap diamondTrap("DiamondTrap");
	std::cout << std::endl;

	std::cout << "Initial state:" << std::endl;
    diamondTrap.whoAmI();
    std::cout << "Hitpoints: " << diamondTrap.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << diamondTrap.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage: " << diamondTrap.getAttackDamage() << std::endl;
	std::cout << std::endl;

	diamondTrap.attack("target");
	diamondTrap.takeDamage(10);
	diamondTrap.beRepaired(5);
	std::cout << std::endl;

	diamondTrap.guardGate();
	diamondTrap.highFivesGuys();
	std::cout << std::endl;

	std::cout << "Destructors:" << std::endl;
	return 0;
}