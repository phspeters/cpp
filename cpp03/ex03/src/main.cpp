#include "DiamondTrap.hpp"

int	main() {
	std::cout << "TESTING CONSTRUCTORS:\n";
	DiamondTrap firstDiamondTrap("First");
	DiamondTrap secondDiamondTrap("Second");
	DiamondTrap thirdDiamondTrap(secondDiamondTrap);
	DiamondTrap fourthDiamondTrap;
	std::cout << '\n';

	std::cout << "TESTING ASSIGNMENT OPERATOR:\n";
	firstDiamondTrap.setHitPoints(42);
	firstDiamondTrap.setEnergyPoints(42);
	std::cout << "Before assignment:\n";
	std::cout << "Name: " << fourthDiamondTrap.getName() << "\t" << "Name: " << firstDiamondTrap.getName() << '\n';
	std::cout << "Hitpoints: " << fourthDiamondTrap.getHitPoints() << "\t\t\t" << "Hitpoints: " << firstDiamondTrap.getHitPoints() << '\n';
	std::cout << "Energy Points: " << fourthDiamondTrap.getEnergyPoints() << "\t\t" << "Energy Points: " << firstDiamondTrap.getEnergyPoints() << '\n';
	std::cout << "Attack Damage: " << fourthDiamondTrap.getAttackDamage() << "\t\t" << "Attack Damage: " << firstDiamondTrap.getAttackDamage() << '\n';
	std::cout << '\n';

	fourthDiamondTrap = firstDiamondTrap;
	std::cout << '\n';

	std::cout << "After assignment:\n";
	std::cout << "Name: " << fourthDiamondTrap.getName() << "\t\t\t" << "Name: " << firstDiamondTrap.getName() << '\n';
	std::cout << "Hitpoints: " << fourthDiamondTrap.getHitPoints() << "\t\t\t" << "Hitpoints: " << firstDiamondTrap.getHitPoints() << '\n';
	std::cout << "Energy Points: " << fourthDiamondTrap.getEnergyPoints() << "\t\t" << "Energy Points: " << firstDiamondTrap.getEnergyPoints() << '\n';
	std::cout << "Attack Damage: " << fourthDiamondTrap.getAttackDamage() << "\t\t" << "Attack Damage: " << firstDiamondTrap.getAttackDamage() << '\n';
	std::cout << '\n';

	std::cout << "INITIAL STATE:\n";
	DiamondTrap diamondtrap("DI4M0ND-TP");
	std::cout << '\n';
	std::cout << "Name: " << diamondtrap.getName() << '\n';
	std::cout << "Hitpoints: " << diamondtrap.getHitPoints() << '\n';
	std::cout << "Energy Points: " << diamondtrap.getEnergyPoints() << '\n';
	std::cout << "Attack Damage: " << diamondtrap.getAttackDamage() << '\n';
	std::cout << '\n';

	diamondtrap.whoAmI();
	diamondtrap.attack("Jack");
	diamondtrap.takeDamage(5);
	diamondtrap.beRepaired(1);
	diamondtrap.guardGate();
	diamondtrap.highFivesGuys();
	std::cout << '\n';

	std::cout << "CURRENT ATTRIBUTES:\n";
	std::cout << diamondtrap.getName() << " has " << diamondtrap.getHitPoints() << " hitpoints\n";
	std::cout << diamondtrap.getName() << " has " << diamondtrap.getEnergyPoints() << " energy points\n";
	std::cout << '\n';

	diamondtrap.setEnergyPoints(0);
	std::cout << "CURRENT ATTRIBUTES:\n";
	std::cout << diamondtrap.getName() << " has " << diamondtrap.getHitPoints() << " hitpoints\n";
	std::cout << diamondtrap.getName() << " has " << diamondtrap.getEnergyPoints() << " energy points\n";
	std::cout << '\n';

	diamondtrap.whoAmI();
	diamondtrap.attack("Jack");
	diamondtrap.takeDamage(5);
	diamondtrap.beRepaired(1);
	diamondtrap.guardGate();
	diamondtrap.highFivesGuys();
	std::cout << '\n';


	diamondtrap.setHitPoints(0);
	diamondtrap.setEnergyPoints(10);
	std::cout << "CURRENT ATTRIBUTES:\n";
	std::cout << diamondtrap.getName() << " has " << diamondtrap.getHitPoints() << " hitpoints\n";
	std::cout << diamondtrap.getName() << " has " << diamondtrap.getEnergyPoints() << " energy points\n";
	std::cout << '\n';
	
	diamondtrap.whoAmI();
	diamondtrap.attack("Jack");
	diamondtrap.takeDamage(5);
	diamondtrap.beRepaired(1);
	diamondtrap.guardGate();
	diamondtrap.highFivesGuys();
	std::cout << '\n';

	std::cout << "TESTING DESTRUCTORS:\n";
	return (0);
}