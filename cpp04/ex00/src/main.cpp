#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	std::cout << "Instantiating Animal, Cat, and Dog objects as Animal *" << std::endl;
	const Animal *animal = new Animal();
	Animal *cat = new Cat();
	const Animal *dog = new Dog();
	std::cout << std::endl;

	std::cout << "Calling makeSound() on each object" << std::endl;
	std::cout << "The "<< cat->getType() << " goes: ";
	cat->makeSound();
	std::cout << "The "<< dog->getType() << " goes: ";
	dog->makeSound();
	std::cout << "The "<< animal->getType() << " goes: ";
	animal->makeSound();
	std::cout << "Because the makeSound() function is virtual, the correct function is called for each object using the vtable" << std::endl;
	std::cout << std::endl;

	std::cout << "But we can use the scope resolution operator to call the makeSound() function of the Animal class" << std::endl;
	std::cout << "The "<< cat->getType() << " goes: ";
	cat->Animal::makeSound();
	std::cout << "The "<< dog->getType() << " goes: ";
	dog->Animal::makeSound();
	std::cout << "The "<< animal->getType() << " goes: ";
	animal->Animal::makeSound();
	std::cout << "This is because the scope resolution operator provides static binding to the base class's implementation, rather than using dynamic dispatch through the vtable." << std::endl;
	std::cout << std::endl;

	std::cout << "Deleting the Animal, Cat, and Dog objects" << std::endl;
	delete animal;
	delete cat;
	delete dog;
	std::cout << std::endl;

	std::cout << "Instantiating a WrongAnimal and WrongCat objects as WrongAnimal *" << std::endl;
	const WrongAnimal *wrongAnimal = new WrongAnimal();
	const WrongAnimal *wrongCat = new WrongCat();
	std::cout << std::endl;

	std::cout << "Calling makeSound() on each object" << std::endl;
	std::cout << "The "<< wrongCat->getType() << " goes: ";
	wrongCat->makeSound();
	std::cout << "The "<< wrongAnimal->getType() << " goes: ";
	wrongAnimal->makeSound();
	std::cout << "Because the makeSound() function is not virtual, the makeSound() function of the base class is called for each object, as they are pointers to the base class." << std::endl;
	std::cout << std::endl;

	std::cout << "Deleting the WrongAnimal and WrongCat objects" << std::endl;
	delete wrongAnimal;
	delete wrongCat;
	
	return (0);
}
