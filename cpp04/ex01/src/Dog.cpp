#include "Dog.hpp"

Dog::Dog() : Animal()
{
	type = "Dog";
	brain = new Brain();

	for (int i = 0; i < 100; i++)
	{
		if (i % 2 == 0)
			brain->setIdea(i, "Sniff");
		else
			brain->setIdea(i, "Play");
	}

	std::cout << "Dog default constructor" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << "Dog copy constructor" << std::endl;
}

Dog &Dog::operator=(const Dog &copy)
{
	if (this != &copy)
	{
		Animal::operator=(copy);
	}

	std::cout << "Dog assignment operator" << std::endl;

	return (*this);
}

Dog::~Dog()
{
	delete brain;
	
	std::cout << "Dog destructor" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woof woof" << std::endl;
}
