#include "FragTrap.hpp"

int	main(void)
{
	std::cout << "Testing constructors, assignment operator and destructor:" << std::endl;
	ClapTrap firstClapTrap("First ClapTrap");
	ClapTrap secondClapTrap("Second ClapTrap");
	ClapTrap thirdClapTrap(secondClapTrap);
	secondClapTrap = firstClapTrap;
	std::cout << std::endl;

	ClapTrap claptrap("CL4P-TP");
	std::cout << std::endl;

	std::cout << "Initial state:" << std::endl;
    std::cout << "Name: " << claptrap.getName() << std::endl;
    std::cout << "Hitpoints: " << claptrap.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << claptrap.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage: " << claptrap.getAttackDamage() << std::endl;
	std::cout << std::endl;

	claptrap.attack("Jack");
	claptrap.takeDamage(5);
	claptrap.beRepaired(1);
	std::cout << std::endl;

	std::cout << "Current atributtes:" << std::endl;
	std::cout << claptrap.getName() << " has " << claptrap.getHitPoints() << " hitpoints" << std::endl;
	std::cout << claptrap.getName() << " has " << claptrap.getEnergyPoints() << " energy points" << std::endl;
	std::cout << std::endl;

	claptrap.setEnergyPoints(0);
	std::cout << std::endl;

	claptrap.attack("Jack");
	claptrap.beRepaired(1);
	std::cout << std::endl;

	std::cout << "Current atributtes:" << std::endl;
	std::cout << claptrap.getName() << " has " << claptrap.getHitPoints() << " hitpoints" << std::endl;
	std::cout << claptrap.getName() << " has " << claptrap.getEnergyPoints() << " energy points" << std::endl;
	std::cout << std::endl;

	claptrap.setEnergyPoints(10);
	claptrap.setHitPoints(0);
	std::cout << std::endl;
	
	claptrap.attack("Jack");
	claptrap.beRepaired(1);
	std::cout << std::endl;

	std::cout << "Current atributtes:" << std::endl;
	std::cout << claptrap.getName() << " has " << claptrap.getHitPoints() << " hitpoints" << std::endl;
	std::cout << claptrap.getName() << " has " << claptrap.getEnergyPoints() << " energy points" << std::endl;
	std::cout << std::endl;


	ScavTrap scavtrap("SC4V-TP");
	std::cout << std::endl;
	
	ScavTrap scavtrap2(scavtrap);
	std::cout << std::endl;

	std::cout << "Destroying ClapTrap objects:" << std::endl;
	return 0;
}