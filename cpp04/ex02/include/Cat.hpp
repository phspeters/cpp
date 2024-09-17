#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
public:
	//constructors
	Cat();
	Cat(const Cat &copy);

	//assignment operator
	Cat &operator=(const Cat &copy);

	//destructor
	~Cat();

	//member functions
	void makeSound() const;
	Brain *getBrain() const;
	
private:
	Brain *_brain;
};

#endif