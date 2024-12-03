#include "Cat.hpp"
#include "Dog.hpp"

# define SIZE 6

void	testingAnimals() {
	Animal *animals[SIZE];

	std::cout << "TESTING CATS AND DOGS AS ANIMAL POINTERS FOR LEAKS\n";

	std::cout << "CREATING ANIMALS\n";
	for (int i = 0; i < SIZE; i++) {
		if (i % 2 == 0) {
			animals[i] = new Dog();
		}
		else {
			animals[i] = new Cat();
		}
	}
	std::cout << '\n';

	std::cout << "MAKING SOUNDS\n";
	for (int i = 0; i < SIZE; i++) {
		animals[i]->makeSound();
	}
	std::cout << '\n';

	std::cout << "DELETING ANIMALS\n";
	for (int i = 0; i < SIZE; i++) {
		delete animals[i];
	}
	std::cout << '\n';
}

void	testingCats() {
	std::cout << "TESTING DEEP COPY OF CATS ALLOCATED ON THE HEAP\n";

	std::cout << "Creating a Cat named Padme\n";
	Cat *Pippin = new Cat();
	std::cout << '\n';

	Pippin->getBrain()->setIdea(0, "Eat");
	Pippin->getBrain()->setIdea(1, "Sleep");
	Pippin->getBrain()->setIdea(2, "Play");
	Pippin->getBrain()->setIdea(3, "Purr");

	std::cout << "Padme's ideas:\n";
	for (int i = 0; i < 4; i++) {
		std::cout << Pippin->getBrain()->getIdea(i) << '\n';
	}
	std::cout << '\n';

	std::cout << "Creating a Cat named Pippin by copying Padme\n";
	Cat *Padme = new Cat(*Pippin);
	std::cout << '\n';

	std::cout << "Pippin's ideas:\n";
	for (int i = 0; i < 4; i++) {
		std::cout << Padme->getBrain()->getIdea(i) << '\n';
	}
	std::cout << '\n';

	std::cout << "Changing Padme's ideas\n";
	Pippin->getBrain()->setIdea(0, "Eat more");
	Pippin->getBrain()->setIdea(1, "Sleep more");
	Pippin->getBrain()->setIdea(2, "Play more");
	Pippin->getBrain()->setIdea(3, "Purr louder");
	std::cout << '\n';

	std::cout << "Padme's ideas:\n";
	for (int i = 0; i < 4; i++) {
		std::cout << Pippin->getBrain()->getIdea(i) << '\n';
	}
	std::cout << '\n';

	std::cout << "Pippin's ideas:\n";
	for (int i = 0; i < 4; i++) {
		std::cout << Padme->getBrain()->getIdea(i) << '\n';
	}
	std::cout << '\n';
	
	delete Pippin;
	delete Padme;
	std::cout << '\n';
}

void	testingDogs() {
	std::cout << "TESTING DEEP COPY OF DOGS ALLOCATED ON THE STACK\n";

	std::cout << "Creating a Dog named Caetano\n";
	Dog Caetano;
	std::cout << '\n';

	Caetano.getBrain()->setIdea(0, "Bark");
	Caetano.getBrain()->setIdea(1, "Eat");
	Caetano.getBrain()->setIdea(2, "Sleep");
	Caetano.getBrain()->setIdea(3, "Play");

	std::cout << "Caetano's ideas:\n";
	for (int i = 0; i < 4; i++) {
		std::cout << Caetano.getBrain()->getIdea(i) << '\n';
	}
	std::cout << '\n';

	std::cout << "Creating a Dog named Madalena by copying Caetano\n";
	Dog Madalena(Caetano);
	std::cout << '\n';

	std::cout << "Madalena's ideas:\n";
	for (int i = 0; i < 4; i++) {
		std::cout << Madalena.getBrain()->getIdea(i) << '\n';
	}
	std::cout << '\n';

	std::cout << "Changing Caetano's ideas\n";
	Caetano.getBrain()->setIdea(0, "Bark louder");
	Caetano.getBrain()->setIdea(1, "Eat more");
	Caetano.getBrain()->setIdea(2, "Sleep more");
	Caetano.getBrain()->setIdea(3, "Play more");
	std::cout << '\n';

	std::cout << "Caetano's ideas:\n";
	for (int i = 0; i < 4; i++) {
		std::cout << Caetano.getBrain()->getIdea(i) << '\n';
	}
	std::cout << '\n';

	std::cout << "Madalena's ideas:\n";
	for (int i = 0; i < 4; i++) {
		std::cout << Madalena.getBrain()->getIdea(i) << '\n';
	}
	std::cout << '\n';
}

int	main() {
	testingAnimals();
	std::cout << "--------------------------------------------------------------------------------\n\n";
	testingCats();
	std::cout << "--------------------------------------------------------------------------------\n\n";
	testingDogs();
	
	return (0);
}
