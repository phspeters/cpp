#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name) {}

Zombie::~Zombie()
{
	std::cout << name << " is destroyed\n";
}

void Zombie::announce(void) const
{
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}
