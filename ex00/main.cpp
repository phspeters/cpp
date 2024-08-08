#include "Zombie.hpp"

int	main()
{
	std::cout << "Allocating first zombie on the heap" << std::endl;
	Zombie*	zombie1 = newZombie("Zombie1");
	std::cout << "Allocating second zombie on the heap" << std::endl;
	Zombie*	zombie2 = newZombie("Zombie2");
	std::cout << std::endl;


	std::cout << "First zombie announcing itself" << std::endl;
	zombie1->announce();
	std::cout << "Second zombie announcing itself" << std::endl;
	zombie2->announce();
	std::cout << std::endl;



	std::cout << "Allocating third zombie on the stack" << std::endl;
	randomChump("Zombie3");
	std::cout << std::endl;


	std::cout << "Deleting first zombie allocated on the heap" << std::endl;
	delete zombie1;
	std::cout << "Deleting second zombie allocated on the heap" << std::endl;
	delete zombie2;

	return (0);
}
