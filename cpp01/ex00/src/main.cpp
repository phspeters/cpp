#include "Zombie.hpp"

int	main() {
	std::cout << "Allocating first zombie on the heap\n";
	Zombie*	zombie1 = newZombie("Zombie1");
	std::cout << "Allocating second zombie on the heap\n";
	Zombie*	zombie2 = newZombie("Zombie2");
	std::cout << '\n';

	std::cout << "First zombie announcing itself\n";
	zombie1->announce();
	std::cout << "Second zombie announcing itself\n";
	zombie2->announce();
	std::cout << '\n';

	std::cout << "Allocating third zombie on the stack\n";
	randomChump("Zombie3");
	std::cout << '\n';

	std::cout << "Allocating fourth zombie on the stack\n";
	randomChump("Zombie4");
	std::cout << '\n';

	std::cout << "Deleting first zombie allocated on the heap\n";
	delete zombie1;
	std::cout << "Deleting second zombie allocated on the heap\n";
	delete zombie2;

	return (0);
}
