#include "Zombie.hpp"

int	main()
{
	int hordeSize = HORDE_SIZE;
	std::string name = HORDE_NAME;

	std::cout << "Allocating Zombie horde of " << hordeSize << " zombies on the heap:" << std::endl;
	Zombie* horde = zombieHorde(hordeSize, name);
	std::cout << std::endl;


	std::cout << "Announcing the horde:" << std::endl;
	for (int i = 0; i < HORDE_SIZE; i++)
		horde[i].announce();
	std::cout << std::endl;


	std::cout << "Deallocating Zombie horde:" << std::endl;
	delete[] horde;
	std::cout << std::endl;

	return (0);
}
