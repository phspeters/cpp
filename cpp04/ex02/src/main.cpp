#include "Cat.hpp"
#include "Dog.hpp"

int	main() {
	std::cout << "CREATING ANIMAL OBJECTS ON THE STACK\n";
	//Animal animal;
	Cat cat;
	Dog dog;
	std::cout << '\n';

	std::cout << "CALLING makeSound() ON ANIMAL OBJECTS\n";
	cat.makeSound();
	dog.makeSound();
	std::cout << '\n';

	std::cout << "CREATING ANIMAL OBJECTS ON THE HEAP\n";
	//Animal *animal2 = new Animal();
	Animal *cat2 = new Cat(cat);
	Animal *dog2 = new Dog(dog);
	std::cout << '\n';

	std::cout << "CALLING makeSound() ON ANIMAL OBJECTS\n";
	cat2->makeSound();
	dog2->makeSound();
	std::cout << '\n';

	std::cout << "DELETING ANIMAL OBJECTS ON THE HEAP\n";
	delete cat2;
	delete dog2;
	std::cout << '\n';
	
	std::cout << "DELETING ANIMAL OBJECTS ON THE STACK\n";
	return (0);
}
