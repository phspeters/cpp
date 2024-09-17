#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
	std::cout << "CREATING ANIMAL OBJECTS ON THE STACK" << std::endl;
	//Animal animal;
	Cat cat;
	Dog dog;
	std::cout << std::endl;

	std::cout << "CALLING makeSound() ON ANIMAL OBJECTS" << std::endl;
	cat.makeSound();
	dog.makeSound();
	std::cout << std::endl;

	std::cout << "CREATING ANIMAL OBJECTS ON THE HEAP" << std::endl;
	//Animal *animal2 = new Animal();
	Animal *cat2 = new Cat(cat);
	Animal *dog2 = new Dog(dog);
	std::cout << std::endl;

	std::cout << "CALLING makeSound() ON ANIMAL OBJECTS" << std::endl;
	cat2->makeSound();
	dog2->makeSound();
	std::cout << std::endl;

	std::cout << "DELETING ANIMAL OBJECTS ON THE HEAP" << std::endl;
	delete cat2;
	delete dog2;
	std::cout << std::endl;
	
	std::cout << "DELETING ANIMAL OBJECTS ON THE STACK" << std::endl;
	return (0);
}
