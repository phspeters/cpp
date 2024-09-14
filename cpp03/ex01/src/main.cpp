#include "ScavTrap.hpp"

int	main(void)
{
	std::cout << "TESTING CONSTRUCTORS:" << std::endl;
	ScavTrap firstScavTrap("First");
	ScavTrap secondScavTrap("Second");
	ScavTrap thirdScavTrap(secondScavTrap);
	ScavTrap fourthScavTrap;
	std::cout << std::endl;

	std::cout << "TESTING ASSIGNMENT OPERATOR:" << std::endl;
	firstScavTrap.setHitPoints(42);
	firstScavTrap.setEnergyPoints(42);
	std::cout << "Before assignment:" << std::endl;
	std::cout << "Name: " << fourthScavTrap.getName() << "\t" << "Name: " << firstScavTrap.getName() << std::endl;
	std::cout << "Hitpoints: " << fourthScavTrap.getHitPoints() << "\t\t\t" << "Hitpoints: " << firstScavTrap.getHitPoints() << std::endl;
	std::cout << "Energy Points: " << fourthScavTrap.getEnergyPoints() << "\t\t" << "Energy Points: " << firstScavTrap.getEnergyPoints() << std::endl;
	std::cout << "Attack Damage: " << fourthScavTrap.getAttackDamage() << "\t\t" << "Attack Damage: " << firstScavTrap.getAttackDamage() << std::endl;
	std::cout << std::endl;

	fourthScavTrap = firstScavTrap;
	std::cout << std::endl;

	std::cout << "After assignment:" << std::endl;
	std::cout << "Name: " << fourthScavTrap.getName() << "\t\t\t" << "Name: " << firstScavTrap.getName() << std::endl;
	std::cout << "Hitpoints: " << fourthScavTrap.getHitPoints() << "\t\t\t" << "Hitpoints: " << firstScavTrap.getHitPoints() << std::endl;
	std::cout << "Energy Points: " << fourthScavTrap.getEnergyPoints() << "\t\t" << "Energy Points: " << firstScavTrap.getEnergyPoints() << std::endl;
	std::cout << "Attack Damage: " << fourthScavTrap.getAttackDamage() << "\t\t" << "Attack Damage: " << firstScavTrap.getAttackDamage() << std::endl;
	std::cout << std::endl;

	std::cout << "INITIAL STATE:" << std::endl;
	ScavTrap scavtrap("SC4V-TP");
	std::cout << std::endl;
    std::cout << "Name: " << scavtrap.getName() << std::endl;
    std::cout << "Hitpoints: " << scavtrap.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << scavtrap.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage: " << scavtrap.getAttackDamage() << std::endl;
	std::cout << std::endl;

	scavtrap.attack("Jack");
	scavtrap.takeDamage(5);
	scavtrap.beRepaired(1);
	scavtrap.guardGate();
	std::cout << std::endl;

	std::cout << "CURRENT ATTRIBUTES:" << std::endl;
	std::cout << scavtrap.getName() << " has " << scavtrap.getHitPoints() << " hitpoints" << std::endl;
	std::cout << scavtrap.getName() << " has " << scavtrap.getEnergyPoints() << " energy points" << std::endl;
	std::cout << std::endl;

	scavtrap.setEnergyPoints(0);
	std::cout << "CURRENT ATTRIBUTES:" << std::endl;
	std::cout << scavtrap.getName() << " has " << scavtrap.getHitPoints() << " hitpoints" << std::endl;
	std::cout << scavtrap.getName() << " has " << scavtrap.getEnergyPoints() << " energy points" << std::endl;
	std::cout << std::endl;

	scavtrap.attack("Jack");
	scavtrap.takeDamage(5);
	scavtrap.beRepaired(1);
	scavtrap.guardGate();
	std::cout << std::endl;


	scavtrap.setHitPoints(0);
	scavtrap.setEnergyPoints(10);
	std::cout << "CURRENT ATTRIBUTES:" << std::endl;
	std::cout << scavtrap.getName() << " has " << scavtrap.getHitPoints() << " hitpoints" << std::endl;
	std::cout << scavtrap.getName() << " has " << scavtrap.getEnergyPoints() << " energy points" << std::endl;
	std::cout << std::endl;
	
	scavtrap.attack("Jack");
	scavtrap.takeDamage(5);
	scavtrap.beRepaired(1);
	scavtrap.guardGate();
	std::cout << std::endl;

	std::cout << "TESTING DESTRUCTORS:" << std::endl;
	return 0;
}