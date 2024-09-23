#include "ScavTrap.hpp"

int	main(void)
{
	std::cout << "TESTING CONSTRUCTORS:\n";
	ScavTrap firstScavTrap("First");
	ScavTrap secondScavTrap("Second");
	ScavTrap thirdScavTrap(secondScavTrap);
	ScavTrap fourthScavTrap;
	std::cout << '\n';

	std::cout << "TESTING ASSIGNMENT OPERATOR:\n";
	firstScavTrap.setHitPoints(42);
	firstScavTrap.setEnergyPoints(42);
	std::cout << "Before assignment:\n";
	std::cout << "Name: " << fourthScavTrap.getName() << "\t" << "Name: " << firstScavTrap.getName() << '\n';
	std::cout << "Hitpoints: " << fourthScavTrap.getHitPoints() << "\t\t\t" << "Hitpoints: " << firstScavTrap.getHitPoints() << '\n';
	std::cout << "Energy Points: " << fourthScavTrap.getEnergyPoints() << "\t\t" << "Energy Points: " << firstScavTrap.getEnergyPoints() << '\n';
	std::cout << "Attack Damage: " << fourthScavTrap.getAttackDamage() << "\t\t" << "Attack Damage: " << firstScavTrap.getAttackDamage() << '\n';
	std::cout << '\n';

	fourthScavTrap = firstScavTrap;
	std::cout << '\n';

	std::cout << "After assignment:\n";
	std::cout << "Name: " << fourthScavTrap.getName() << "\t\t\t" << "Name: " << firstScavTrap.getName() << '\n';
	std::cout << "Hitpoints: " << fourthScavTrap.getHitPoints() << "\t\t\t" << "Hitpoints: " << firstScavTrap.getHitPoints() << '\n';
	std::cout << "Energy Points: " << fourthScavTrap.getEnergyPoints() << "\t\t" << "Energy Points: " << firstScavTrap.getEnergyPoints() << '\n';
	std::cout << "Attack Damage: " << fourthScavTrap.getAttackDamage() << "\t\t" << "Attack Damage: " << firstScavTrap.getAttackDamage() << '\n';
	std::cout << '\n';

	std::cout << "INITIAL STATE:\n";
	ScavTrap scavtrap("SC4V-TP");
	std::cout << '\n';
    std::cout << "Name: " << scavtrap.getName() << '\n';
    std::cout << "Hitpoints: " << scavtrap.getHitPoints() << '\n';
    std::cout << "Energy Points: " << scavtrap.getEnergyPoints() << '\n';
    std::cout << "Attack Damage: " << scavtrap.getAttackDamage() << '\n';
	std::cout << '\n';

	scavtrap.attack("Jack");
	scavtrap.takeDamage(5);
	scavtrap.beRepaired(1);
	scavtrap.guardGate();
	std::cout << '\n';

	std::cout << "CURRENT ATTRIBUTES:\n";
	std::cout << scavtrap.getName() << " has " << scavtrap.getHitPoints() << " hitpoints\n";
	std::cout << scavtrap.getName() << " has " << scavtrap.getEnergyPoints() << " energy points\n";
	std::cout << '\n';

	scavtrap.setEnergyPoints(0);
	std::cout << "CURRENT ATTRIBUTES:\n";
	std::cout << scavtrap.getName() << " has " << scavtrap.getHitPoints() << " hitpoints\n";
	std::cout << scavtrap.getName() << " has " << scavtrap.getEnergyPoints() << " energy points\n";
	std::cout << '\n';

	scavtrap.attack("Jack");
	scavtrap.takeDamage(5);
	scavtrap.beRepaired(1);
	scavtrap.guardGate();
	std::cout << '\n';


	scavtrap.setHitPoints(0);
	scavtrap.setEnergyPoints(10);
	std::cout << "CURRENT ATTRIBUTES:\n";
	std::cout << scavtrap.getName() << " has " << scavtrap.getHitPoints() << " hitpoints\n";
	std::cout << scavtrap.getName() << " has " << scavtrap.getEnergyPoints() << " energy points\n";
	std::cout << '\n';
	
	scavtrap.attack("Jack");
	scavtrap.takeDamage(5);
	scavtrap.beRepaired(1);
	scavtrap.guardGate();
	std::cout << '\n';

	std::cout << "TESTING DESTRUCTORS:\n";
	return 0;
}