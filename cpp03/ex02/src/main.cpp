#include "FragTrap.hpp"

int	main(void)
{
	std::cout << "TESTING CONSTRUCTORS:" << std::endl;
	FragTrap firstFragTrap("First");
	FragTrap secondFragTrap("Second");
	FragTrap thirdFragTrap(secondFragTrap);
	FragTrap fourthFragTrap;
	std::cout << std::endl;

	std::cout << "TESTING ASSIGNMENT OPERATOR:" << std::endl;
	firstFragTrap.setHitPoints(42);
	firstFragTrap.setEnergyPoints(42);
	std::cout << "Before assignment:" << std::endl;
	std::cout << "Name: " << fourthFragTrap.getName() << "\t" << "Name: " << firstFragTrap.getName() << std::endl;
	std::cout << "Hitpoints: " << fourthFragTrap.getHitPoints() << "\t\t\t" << "Hitpoints: " << firstFragTrap.getHitPoints() << std::endl;
	std::cout << "Energy Points: " << fourthFragTrap.getEnergyPoints() << "\t\t" << "Energy Points: " << firstFragTrap.getEnergyPoints() << std::endl;
	std::cout << "Attack Damage: " << fourthFragTrap.getAttackDamage() << "\t\t" << "Attack Damage: " << firstFragTrap.getAttackDamage() << std::endl;
	std::cout << std::endl;

	fourthFragTrap = firstFragTrap;
	std::cout << std::endl;

	std::cout << "After assignment:" << std::endl;
	std::cout << "Name: " << fourthFragTrap.getName() << "\t\t\t" << "Name: " << firstFragTrap.getName() << std::endl;
	std::cout << "Hitpoints: " << fourthFragTrap.getHitPoints() << "\t\t\t" << "Hitpoints: " << firstFragTrap.getHitPoints() << std::endl;
	std::cout << "Energy Points: " << fourthFragTrap.getEnergyPoints() << "\t\t" << "Energy Points: " << firstFragTrap.getEnergyPoints() << std::endl;
	std::cout << "Attack Damage: " << fourthFragTrap.getAttackDamage() << "\t\t" << "Attack Damage: " << firstFragTrap.getAttackDamage() << std::endl;
	std::cout << std::endl;

	std::cout << "INITIAL STATE:" << std::endl;
	FragTrap fragtrap("FR4G-TP");
	std::cout << std::endl;
    std::cout << "Name: " << fragtrap.getName() << std::endl;
    std::cout << "Hitpoints: " << fragtrap.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << fragtrap.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage: " << fragtrap.getAttackDamage() << std::endl;
	std::cout << std::endl;

	fragtrap.attack("Jack");
	fragtrap.takeDamage(5);
	fragtrap.beRepaired(1);
	fragtrap.highFivesGuys();
	std::cout << std::endl;

	std::cout << "CURRENT ATTRIBUTES:" << std::endl;
	std::cout << fragtrap.getName() << " has " << fragtrap.getHitPoints() << " hitpoints" << std::endl;
	std::cout << fragtrap.getName() << " has " << fragtrap.getEnergyPoints() << " energy points" << std::endl;
	std::cout << std::endl;

	fragtrap.setEnergyPoints(0);
	std::cout << "CURRENT ATTRIBUTES:" << std::endl;
	std::cout << fragtrap.getName() << " has " << fragtrap.getHitPoints() << " hitpoints" << std::endl;
	std::cout << fragtrap.getName() << " has " << fragtrap.getEnergyPoints() << " energy points" << std::endl;
	std::cout << std::endl;

	fragtrap.attack("Jack");
	fragtrap.takeDamage(5);
	fragtrap.beRepaired(1);
	fragtrap.highFivesGuys();
	std::cout << std::endl;


	fragtrap.setHitPoints(0);
	fragtrap.setEnergyPoints(10);
	std::cout << "CURRENT ATTRIBUTES:" << std::endl;
	std::cout << fragtrap.getName() << " has " << fragtrap.getHitPoints() << " hitpoints" << std::endl;
	std::cout << fragtrap.getName() << " has " << fragtrap.getEnergyPoints() << " energy points" << std::endl;
	std::cout << std::endl;
	
	fragtrap.attack("Jack");
	fragtrap.takeDamage(5);
	fragtrap.beRepaired(1);
	fragtrap.highFivesGuys();
	std::cout << std::endl;

	std::cout << "TESTING DESTRUCTORS:" << std::endl;
	return 0;
}