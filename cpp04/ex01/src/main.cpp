#include "Cat.hpp"
#include "Dog.hpp"

#define SIZE 4

void	testingAnimals(void)
{
	Animal *animals[SIZE];

	std::cout << "TESTING CATS AND DOGS AS ANIMAL POINTERS FOR LEAKS" << std::endl;

	std::cout << "CREATING ANIMALS" << std::endl;
	for (int i = 0; i < SIZE; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	std::cout << std::endl;

	std::cout << "MAKING SOUNDS" << std::endl;
	for (int i = 0; i < SIZE; i++)
	{
		animals[i]->makeSound();
	}
	std::cout << std::endl;

	std::cout << "DELETING ANIMALS" << std::endl;
	for (int i = 0; i < SIZE; i++)
	{
		delete animals[i];
	}
	std::cout << std::endl;
}

void	testingCats(void)
{
	std::cout << "TESTING DEEP COPY OF CATS ALLOCATED ON THE HEAP" << std::endl;

	std::cout << "Creating a Cat named Pippin" << std::endl;
	Cat *Pippin = new Cat();
	std::cout << std::endl;

	Pippin->getBrain()->setIdea(0, "Eat");
	Pippin->getBrain()->setIdea(1, "Sleep");
	Pippin->getBrain()->setIdea(2, "Play");
	Pippin->getBrain()->setIdea(3, "Purr");

	std::cout << "Pippin's ideas:" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		std::cout << Pippin->getBrain()->getIdea(i) << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Creating a Cat named Padme by copying Pippin" << std::endl;
	Cat *Padme = new Cat(*Pippin);
	std::cout << std::endl;

	std::cout << "Padme's ideas:" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		std::cout << Padme->getBrain()->getIdea(i) << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Changing Pippin's ideas" << std::endl;
	Pippin->getBrain()->setIdea(0, "Eat more");
	Pippin->getBrain()->setIdea(1, "Sleep more");
	Pippin->getBrain()->setIdea(2, "Play more");
	Pippin->getBrain()->setIdea(3, "Purr louder");
	std::cout << std::endl;

	std::cout << "Pippin's ideas:" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		std::cout << Pippin->getBrain()->getIdea(i) << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Padme's ideas:" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		std::cout << Padme->getBrain()->getIdea(i) << std::endl;
	}
	std::cout << std::endl;
	
	delete Pippin;
	delete Padme;
	std::cout << std::endl;
}

void	testingDogs(void)
{
	std::cout << "TESTING DEEP COPY OF DOGS ALLOCATED ON THE STACK" << std::endl;

	std::cout << "Creating a Dog named Caetano" << std::endl;
	Dog Caetano;
	std::cout << std::endl;

	Caetano.getBrain()->setIdea(0, "Bark");
	Caetano.getBrain()->setIdea(1, "Eat");
	Caetano.getBrain()->setIdea(2, "Sleep");
	Caetano.getBrain()->setIdea(3, "Play");

	std::cout << "Caetano's ideas:" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		std::cout << Caetano.getBrain()->getIdea(i) << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Creating a Dog named Madalena by copying Caetano" << std::endl;
	Dog Madalena(Caetano);
	std::cout << std::endl;

	std::cout << "Madalena's ideas:" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		std::cout << Madalena.getBrain()->getIdea(i) << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Changing Caetano's ideas" << std::endl;
	Caetano.getBrain()->setIdea(0, "Bark louder");
	Caetano.getBrain()->setIdea(1, "Eat more");
	Caetano.getBrain()->setIdea(2, "Sleep more");
	Caetano.getBrain()->setIdea(3, "Play more");
	std::cout << std::endl;

	std::cout << "Caetano's ideas:" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		std::cout << Caetano.getBrain()->getIdea(i) << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Madalena's ideas:" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		std::cout << Madalena.getBrain()->getIdea(i) << std::endl;
	}
	std::cout << std::endl;
}

int	main(void)
{
	testingAnimals();
	testingCats();
	testingDogs();
	
	return (0);
}
