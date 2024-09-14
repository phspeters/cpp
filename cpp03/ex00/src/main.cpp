#include "ClapTrap.hpp"

int	main(void)
{
	std::cout << "TESTING CONSTRUCTORS:" << std::endl;
	ClapTrap firstClapTrap("First");
	ClapTrap secondClapTrap("Second");
	ClapTrap thirdClapTrap(secondClapTrap);
	ClapTrap fourthClapTrap;
	std::cout << std::endl;

	std::cout << "TESTING ASSIGNMENT OPERATOR:" << std::endl;
	firstClapTrap.setHitPoints(5);
	firstClapTrap.setEnergyPoints(4);
	std::cout << "Before assignment:" << std::endl;
	std::cout << "Name: " << fourthClapTrap.getName() << "\t" << "Name: " << firstClapTrap.getName() << std::endl;
	std::cout << "Hitpoints: " << fourthClapTrap.getHitPoints() << "\t\t\t" << "Hitpoints: " << firstClapTrap.getHitPoints() << std::endl;
	std::cout << "Energy Points: " << fourthClapTrap.getEnergyPoints() << "\t\t" << "Energy Points: " << firstClapTrap.getEnergyPoints() << std::endl;
	std::cout << "Attack Damage: " << fourthClapTrap.getAttackDamage() << "\t\t" << "Attack Damage: " << firstClapTrap.getAttackDamage() << std::endl;
	std::cout << std::endl;

	fourthClapTrap = firstClapTrap;
	std::cout << std::endl;

	std::cout << "After assignment:" << std::endl;
	std::cout << "Name: " << fourthClapTrap.getName() << "\t\t\t" << "Name: " << firstClapTrap.getName() << std::endl;
	std::cout << "Hitpoints: " << fourthClapTrap.getHitPoints() << "\t\t\t" << "Hitpoints: " << firstClapTrap.getHitPoints() << std::endl;
	std::cout << "Energy Points: " << fourthClapTrap.getEnergyPoints() << "\t\t" << "Energy Points: " << firstClapTrap.getEnergyPoints() << std::endl;
	std::cout << "Attack Damage: " << fourthClapTrap.getAttackDamage() << "\t\t" << "Attack Damage: " << firstClapTrap.getAttackDamage() << std::endl;
	std::cout << std::endl;

	std::cout << "INITIAL STATE:" << std::endl;
	ClapTrap claptrap("CL4P-TP");
	std::cout << std::endl;
    std::cout << "Name: " << claptrap.getName() << std::endl;
    std::cout << "Hitpoints: " << claptrap.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << claptrap.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage: " << claptrap.getAttackDamage() << std::endl;
	std::cout << std::endl;

	claptrap.attack("Jack");
	claptrap.takeDamage(5);
	claptrap.beRepaired(1);
	std::cout << std::endl;

	std::cout << "CURRENT ATTRIBUTES:" << std::endl;
	std::cout << claptrap.getName() << " has " << claptrap.getHitPoints() << " hitpoints" << std::endl;
	std::cout << claptrap.getName() << " has " << claptrap.getEnergyPoints() << " energy points" << std::endl;
	std::cout << std::endl;

	claptrap.setEnergyPoints(0);
	std::cout << "CURRENT ATTRIBUTES:" << std::endl;
	std::cout << claptrap.getName() << " has " << claptrap.getHitPoints() << " hitpoints" << std::endl;
	std::cout << claptrap.getName() << " has " << claptrap.getEnergyPoints() << " energy points" << std::endl;
	std::cout << std::endl;

	claptrap.attack("Jack");
	claptrap.takeDamage(5);
	claptrap.beRepaired(1);
	std::cout << std::endl;


	claptrap.setHitPoints(0);
	claptrap.setEnergyPoints(10);
	std::cout << "CURRENT ATTRIBUTES:" << std::endl;
	std::cout << claptrap.getName() << " has " << claptrap.getHitPoints() << " hitpoints" << std::endl;
	std::cout << claptrap.getName() << " has " << claptrap.getEnergyPoints() << " energy points" << std::endl;
	std::cout << std::endl;
	
	claptrap.attack("Jack");
	claptrap.takeDamage(5);
	claptrap.beRepaired(1);
	std::cout << std::endl;

	std::cout << "TESTING DESTRUCTORS:" << std::endl;
	return 0;
}