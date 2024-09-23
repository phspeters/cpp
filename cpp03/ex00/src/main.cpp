#include "ClapTrap.hpp"

int	main(void)
{
	std::cout << "TESTING CONSTRUCTORS:\n";
	ClapTrap firstClapTrap("First");
	ClapTrap secondClapTrap("Second");
	ClapTrap thirdClapTrap(secondClapTrap);
	ClapTrap fourthClapTrap;
	std::cout << '\n';

	std::cout << "TESTING ASSIGNMENT OPERATOR:\n";
	firstClapTrap.setHitPoints(5);
	firstClapTrap.setEnergyPoints(4);
	std::cout << "Before assignment:\n";
	std::cout << "Name: " << fourthClapTrap.getName() << "\t" << "Name: " << firstClapTrap.getName() << '\n';
	std::cout << "Hitpoints: " << fourthClapTrap.getHitPoints() << "\t\t\t" << "Hitpoints: " << firstClapTrap.getHitPoints() << '\n';
	std::cout << "Energy Points: " << fourthClapTrap.getEnergyPoints() << "\t\t" << "Energy Points: " << firstClapTrap.getEnergyPoints() << '\n';
	std::cout << "Attack Damage: " << fourthClapTrap.getAttackDamage() << "\t\t" << "Attack Damage: " << firstClapTrap.getAttackDamage() << '\n';
	std::cout << '\n';

	fourthClapTrap = firstClapTrap;
	std::cout << '\n';

	std::cout << "After assignment:\n";
	std::cout << "Name: " << fourthClapTrap.getName() << "\t\t\t" << "Name: " << firstClapTrap.getName() << '\n';
	std::cout << "Hitpoints: " << fourthClapTrap.getHitPoints() << "\t\t\t" << "Hitpoints: " << firstClapTrap.getHitPoints() << '\n';
	std::cout << "Energy Points: " << fourthClapTrap.getEnergyPoints() << "\t\t" << "Energy Points: " << firstClapTrap.getEnergyPoints() << '\n';
	std::cout << "Attack Damage: " << fourthClapTrap.getAttackDamage() << "\t\t" << "Attack Damage: " << firstClapTrap.getAttackDamage() << '\n';
	std::cout << '\n';

	std::cout << "INITIAL STATE:\n";
	ClapTrap claptrap("CL4P-TP");
	std::cout << '\n';
    std::cout << "Name: " << claptrap.getName() << '\n';
    std::cout << "Hitpoints: " << claptrap.getHitPoints() << '\n';
    std::cout << "Energy Points: " << claptrap.getEnergyPoints() << '\n';
    std::cout << "Attack Damage: " << claptrap.getAttackDamage() << '\n';
	std::cout << '\n';

	claptrap.attack("Jack");
	claptrap.takeDamage(5);
	claptrap.beRepaired(1);
	std::cout << '\n';

	std::cout << "CURRENT ATTRIBUTES:\n";
	std::cout << claptrap.getName() << " has " << claptrap.getHitPoints() << " hitpoints\n";
	std::cout << claptrap.getName() << " has " << claptrap.getEnergyPoints() << " energy points\n";
	std::cout << '\n';

	claptrap.setEnergyPoints(0);
	std::cout << "CURRENT ATTRIBUTES:\n";
	std::cout << claptrap.getName() << " has " << claptrap.getHitPoints() << " hitpoints\n";
	std::cout << claptrap.getName() << " has " << claptrap.getEnergyPoints() << " energy points\n";
	std::cout << '\n';

	claptrap.attack("Jack");
	claptrap.takeDamage(5);
	claptrap.beRepaired(1);
	std::cout << '\n';


	claptrap.setHitPoints(0);
	claptrap.setEnergyPoints(10);
	std::cout << "CURRENT ATTRIBUTES:\n";
	std::cout << claptrap.getName() << " has " << claptrap.getHitPoints() << " hitpoints\n";
	std::cout << claptrap.getName() << " has " << claptrap.getEnergyPoints() << " energy points\n";
	std::cout << '\n';
	
	claptrap.attack("Jack");
	claptrap.takeDamage(5);
	claptrap.beRepaired(1);
	std::cout << '\n';

	std::cout << "TESTING DESTRUCTORS:\n";
	return 0;
}