#include "Cat.hpp"

Cat::Cat() : Animal()
{
	_type = "Cat";
	_brain = new Brain();

	std::cout << "Cat default constructor" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(), _brain(NULL)
{
	*this = copy;

	std::cout << "Cat copy constructor" << std::endl;
}

Cat &Cat::operator=(const Cat &copy)
{
	if (this != &copy)
	{
		Animal::operator=(copy);
		if (_brain)
			delete _brain;
		_brain = new Brain(*copy._brain);
	}

	std::cout << "Cat assignment operator" << std::endl;

	return (*this);
}

Cat::~Cat()
{
	delete _brain;
	
	std::cout << "Cat destructor" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow meow" << std::endl;
}

Brain *Cat::getBrain() const
{
	return (_brain);
}
