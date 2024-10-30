#include "FragTrap.hpp"

int	main() {
	std::cout << "TESTING CONSTRUCTORS:\n";
	FragTrap firstFragTrap("First");
	FragTrap secondFragTrap("Second");
	FragTrap thirdFragTrap(secondFragTrap);
	FragTrap fourthFragTrap;
	std::cout << '\n';

	std::cout << "TESTING ASSIGNMENT OPERATOR:\n";
	firstFragTrap.setHitPoints(42);
	firstFragTrap.setEnergyPoints(42);
	std::cout << "Before assignment:\n";
	std::cout << "Name: " << fourthFragTrap.getName() << "\t" << "Name: " << firstFragTrap.getName() << '\n';
	std::cout << "Hitpoints: " << fourthFragTrap.getHitPoints() << "\t\t\t" << "Hitpoints: " << firstFragTrap.getHitPoints() << '\n';
	std::cout << "Energy Points: " << fourthFragTrap.getEnergyPoints() << "\t\t" << "Energy Points: " << firstFragTrap.getEnergyPoints() << '\n';
	std::cout << "Attack Damage: " << fourthFragTrap.getAttackDamage() << "\t\t" << "Attack Damage: " << firstFragTrap.getAttackDamage() << '\n';
	std::cout << '\n';

	fourthFragTrap = firstFragTrap;
	std::cout << '\n';

	std::cout << "After assignment:\n";
	std::cout << "Name: " << fourthFragTrap.getName() << "\t\t\t" << "Name: " << firstFragTrap.getName() << '\n';
	std::cout << "Hitpoints: " << fourthFragTrap.getHitPoints() << "\t\t\t" << "Hitpoints: " << firstFragTrap.getHitPoints() << '\n';
	std::cout << "Energy Points: " << fourthFragTrap.getEnergyPoints() << "\t\t" << "Energy Points: " << firstFragTrap.getEnergyPoints() << '\n';
	std::cout << "Attack Damage: " << fourthFragTrap.getAttackDamage() << "\t\t" << "Attack Damage: " << firstFragTrap.getAttackDamage() << '\n';
	std::cout << '\n';

	std::cout << "INITIAL STATE:\n";
	FragTrap fragtrap("FR4G-TP");
	std::cout << '\n';
	std::cout << "Name: " << fragtrap.getName() << '\n';
	std::cout << "Hitpoints: " << fragtrap.getHitPoints() << '\n';
	std::cout << "Energy Points: " << fragtrap.getEnergyPoints() << '\n';
	std::cout << "Attack Damage: " << fragtrap.getAttackDamage() << '\n';
	std::cout << '\n';

	fragtrap.attack("Jack");
	fragtrap.takeDamage(5);
	fragtrap.beRepaired(1);
	fragtrap.highFivesGuys();
	std::cout << '\n';

	std::cout << "CURRENT ATTRIBUTES:\n";
	std::cout << fragtrap.getName() << " has " << fragtrap.getHitPoints() << " hitpoints\n";
	std::cout << fragtrap.getName() << " has " << fragtrap.getEnergyPoints() << " energy points\n";
	std::cout << '\n';

	fragtrap.setEnergyPoints(0);
	std::cout << "CURRENT ATTRIBUTES:\n";
	std::cout << fragtrap.getName() << " has " << fragtrap.getHitPoints() << " hitpoints\n";
	std::cout << fragtrap.getName() << " has " << fragtrap.getEnergyPoints() << " energy points\n";
	std::cout << '\n';

	fragtrap.attack("Jack");
	fragtrap.takeDamage(5);
	fragtrap.beRepaired(1);
	fragtrap.highFivesGuys();
	std::cout << '\n';


	fragtrap.setHitPoints(0);
	fragtrap.setEnergyPoints(10);
	std::cout << "CURRENT ATTRIBUTES:\n";
	std::cout << fragtrap.getName() << " has " << fragtrap.getHitPoints() << " hitpoints\n";
	std::cout << fragtrap.getName() << " has " << fragtrap.getEnergyPoints() << " energy points\n";
	std::cout << '\n';
	
	fragtrap.attack("Jack");
	fragtrap.takeDamage(5);
	fragtrap.beRepaired(1);
	fragtrap.highFivesGuys();
	std::cout << '\n';

	std::cout << "TESTING DESTRUCTORS:\n";
	return (0);
}