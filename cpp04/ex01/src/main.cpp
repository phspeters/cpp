#include "Cat.hpp"
#include "Dog.hpp"

#define SIZE 12

int	main(void)
{
	Animal animals[SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		if (i % 2 == 0)
			animals[i] = Dog();
		else
			animals[i] = Cat();
	}

	return (0);
}
