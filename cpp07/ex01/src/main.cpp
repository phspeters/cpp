#include "iter.hpp"

int	main() {
	int intArray[] = {1, 2, 3, 4, 5};
	float floatArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	std::string stringArray[] = {"one", "two", "three", "four", "five"};

	std::cout << "INTEGER ARRAY:'\n";
	std::cout << "Printing members:\n";
	iter(intArray, 5, print);
	std::cout << '\n';

	std::cout << "..Adding one to every member\n";
	std::cout << '\n';

	iter(intArray, 5, sumOne);
	std::cout << "Printing members again:\n";
	iter(intArray, 5, print);
	std::cout << '\n';

	std::cout << "FLOAT ARRAY:\n";
	std::cout << "Printing members:\n";
	iter(floatArray, 5, print);
	std::cout << '\n';

	std::cout << "... Adding one to every member\n";
	std::cout << '\n';

	iter(floatArray, 5, sumOne);
	std::cout << "Printing members again:\n";
	iter(floatArray, 5, print);
	std::cout << '\n';

	std::cout << "STRING ARRAY:\n";
	std::cout << "Printing members:\n";
	iter(stringArray, 5, print);
	std::cout << '\n';

	std::cout << "... Appending '!' at the end of every string\n";
	std::cout << '\n';
	
	iter(stringArray, 5, append);
	std::cout << "Printing members again:\n";
	iter(stringArray, 5, print);
	std::cout << '\n';

	return (0);
}