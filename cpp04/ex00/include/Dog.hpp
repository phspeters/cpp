#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
public:
	//constructors
	Dog();
	Dog(const Dog &copy);

	//assignation operator
	Dog &operator=(const Dog &copy);

	//destructor
	~Dog();

	//member functions
	void makeSound() const;
};

#endif