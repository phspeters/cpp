#include "Cat.hpp"

Cat::Cat() : Animal()
{
	type = "Cat";
	
	std::cout << "Cat default constructor" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	std::cout << "Cat copy constructor" << std::endl;
}

Cat &Cat::operator=(const Cat &copy)
{
	if (this != &copy)
	{
		Animal::operator=(copy);
	}

	std::cout << "Cat assignment operator" << std::endl;

	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow meow" << std::endl;
}
