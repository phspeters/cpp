#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
	//constructors
	WrongCat();
	WrongCat(const WrongCat &copy);

	//assignment operator
	WrongCat &operator=(const WrongCat &copy);

	//destructor
	~WrongCat();

	//member functions
	void makeSound() const;
};

#endif