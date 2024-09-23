#include "Zombie.hpp"

int	main()
{
	int hordeSize = HORDE_SIZE;
	std::string name = HORDE_NAME;

	std::cout << "Allocating Zombie horde of " << hordeSize << " zombies on the heap:\n";
	Zombie* horde = zombieHorde(hordeSize, name);
	std::cout << '\n';


	std::cout << "Announcing the horde:\n";
	for (int i = 0; i < HORDE_SIZE; i++)
		horde[i].announce();
	std::cout << '\n';


	std::cout << "Deallocating Zombie horde:\n";
	delete[] horde;
	std::cout << '\n';

	return (0);
}
