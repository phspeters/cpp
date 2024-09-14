#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	if (N <= 0)
		return (NULL);

	Zombie* horde = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		std::stringstream ss;
		ss << name << i + 1;
		horde[i].setName(ss.str());
	}

	return (horde);
}
