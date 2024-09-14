#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <sstream>

#define HORDE_NAME "Zombie"
#define HORDE_SIZE 5

class Zombie
{
private:
	std::string name;

public:
	Zombie();
	Zombie(std::string name);
	~Zombie();
	void announce() const;
	void setName(std::string name);
};

Zombie* zombieHorde(int N, std::string name);

#endif