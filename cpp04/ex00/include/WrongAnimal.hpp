#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
public:
	//constructors
	WrongAnimal();
	WrongAnimal(const WrongAnimal &copy);

	//assignation operator
	WrongAnimal &operator=(const WrongAnimal &copy);

	//destructor
	~WrongAnimal();

	//member functions
	std::string getType() const;
	void makeSound() const;

protected:
	std::string type;
};

#endif