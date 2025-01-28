#include "iter.hpp"

void toUpper(char &c) {
	c = std::toupper(c);
}

int	main() {
	int intArray[] = {1, 2, 3, 4, 5};
	double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	std::string stringArray[] = {"one", "two", "three", "four", "five"};
	char charArray[] = {'a', 'b', 'c', 'd', 'e'};

	std::cout << "INTEGER ARRAY:'\n";
	std::cout << "Printing members:\n";
	iter(intArray, 5, print);
	std::cout << '\n';

	std::cout << "... Adding one to every member\n";
	std::cout << '\n';

	iter(intArray, 5, sumOne);
	std::cout << "Printing members again:\n";
	iter(intArray, 5, print);
	std::cout << '\n';

	std::cout << "DOUBLE ARRAY:\n";
	std::cout << "Printing members:\n";
	iter(doubleArray, 5, print);
	std::cout << '\n';

	std::cout << "... Adding one to every member\n";
	std::cout << '\n';

	iter(doubleArray, 5, sumOne);
	std::cout << "Printing members again:\n";
	iter(doubleArray, 5, print);
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

	std::cout << "CHAR ARRAY:\n";
	std::cout << "Printing members:\n";
	iter(charArray, 5, print);
	std::cout << '\n';

	std::cout << "... Converting every character to upper case\n";
	std::cout << '\n';

	iter(charArray, 5, &toUpper);
	std::cout << "Printing members again:\n";
	iter(charArray, 5, print);

	return (0);
}