#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "Animal default constructor" << std::endl;
}

Animal::Animal(const Animal &copy) : type(copy.type)
{
	std::cout << "Animal copy constructor" << std::endl;
}

Animal &Animal::operator=(const Animal &copy)
{
	if (this != &copy)
	{
		type = copy.type;
	}

	std::cout << "Animal assignment operator" << std::endl;

	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor" << std::endl;
}

std::string Animal::getType() const
{
	return (type);
}

void Animal::makeSound() const
{
	std::cout << "*Animal noises*" << std::endl;
}
