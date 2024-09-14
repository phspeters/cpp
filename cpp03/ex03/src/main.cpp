#include "DiamondTrap.hpp"

int	main(void)
{
	std::cout << "TESTING CONSTRUCTORS:" << std::endl;
	DiamondTrap firstDiamondTrap("First");
	DiamondTrap secondDiamondTrap("Second");
	DiamondTrap thirdDiamondTrap(secondDiamondTrap);
	DiamondTrap fourthDiamondTrap;
	std::cout << std::endl;

	std::cout << "TESTING ASSIGNMENT OPERATOR:" << std::endl;
	firstDiamondTrap.setHitPoints(42);
	firstDiamondTrap.setEnergyPoints(42);
	std::cout << "Before assignment:" << std::endl;
	std::cout << "Name: " << fourthDiamondTrap.getName() << "\t" << "Name: " << firstDiamondTrap.getName() << std::endl;
	std::cout << "Hitpoints: " << fourthDiamondTrap.getHitPoints() << "\t\t\t" << "Hitpoints: " << firstDiamondTrap.getHitPoints() << std::endl;
	std::cout << "Energy Points: " << fourthDiamondTrap.getEnergyPoints() << "\t\t" << "Energy Points: " << firstDiamondTrap.getEnergyPoints() << std::endl;
	std::cout << "Attack Damage: " << fourthDiamondTrap.getAttackDamage() << "\t\t" << "Attack Damage: " << firstDiamondTrap.getAttackDamage() << std::endl;
	std::cout << std::endl;

	fourthDiamondTrap = firstDiamondTrap;
	std::cout << std::endl;

	std::cout << "After assignment:" << std::endl;
	std::cout << "Name: " << fourthDiamondTrap.getName() << "\t\t\t" << "Name: " << firstDiamondTrap.getName() << std::endl;
	std::cout << "Hitpoints: " << fourthDiamondTrap.getHitPoints() << "\t\t\t" << "Hitpoints: " << firstDiamondTrap.getHitPoints() << std::endl;
	std::cout << "Energy Points: " << fourthDiamondTrap.getEnergyPoints() << "\t\t" << "Energy Points: " << firstDiamondTrap.getEnergyPoints() << std::endl;
	std::cout << "Attack Damage: " << fourthDiamondTrap.getAttackDamage() << "\t\t" << "Attack Damage: " << firstDiamondTrap.getAttackDamage() << std::endl;
	std::cout << std::endl;

	std::cout << "INITIAL STATE:" << std::endl;
	DiamondTrap diamondtrap("DI4M0ND-TP");
	std::cout << std::endl;
    std::cout << "Name: " << diamondtrap.getName() << std::endl;
    std::cout << "Hitpoints: " << diamondtrap.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << diamondtrap.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage: " << diamondtrap.getAttackDamage() << std::endl;
	std::cout << std::endl;

	diamondtrap.whoAmI();
	diamondtrap.attack("Jack");
	diamondtrap.takeDamage(5);
	diamondtrap.beRepaired(1);
	diamondtrap.guardGate();
	diamondtrap.highFivesGuys();
	std::cout << std::endl;

	std::cout << "CURRENT ATTRIBUTES:" << std::endl;
	std::cout << diamondtrap.getName() << " has " << diamondtrap.getHitPoints() << " hitpoints" << std::endl;
	std::cout << diamondtrap.getName() << " has " << diamondtrap.getEnergyPoints() << " energy points" << std::endl;
	std::cout << std::endl;

	diamondtrap.setEnergyPoints(0);
	std::cout << "CURRENT ATTRIBUTES:" << std::endl;
	std::cout << diamondtrap.getName() << " has " << diamondtrap.getHitPoints() << " hitpoints" << std::endl;
	std::cout << diamondtrap.getName() << " has " << diamondtrap.getEnergyPoints() << " energy points" << std::endl;
	std::cout << std::endl;

	diamondtrap.whoAmI();
	diamondtrap.attack("Jack");
	diamondtrap.takeDamage(5);
	diamondtrap.beRepaired(1);
	diamondtrap.guardGate();
	diamondtrap.highFivesGuys();
	std::cout << std::endl;


	diamondtrap.setHitPoints(0);
	diamondtrap.setEnergyPoints(10);
	std::cout << "CURRENT ATTRIBUTES:" << std::endl;
	std::cout << diamondtrap.getName() << " has " << diamondtrap.getHitPoints() << " hitpoints" << std::endl;
	std::cout << diamondtrap.getName() << " has " << diamondtrap.getEnergyPoints() << " energy points" << std::endl;
	std::cout << std::endl;
	
	diamondtrap.whoAmI();
	diamondtrap.attack("Jack");
	diamondtrap.takeDamage(5);
	diamondtrap.beRepaired(1);
	diamondtrap.guardGate();
	diamondtrap.highFivesGuys();
	std::cout << std::endl;

	std::cout << "TESTING DESTRUCTORS:" << std::endl;
	return 0;
}