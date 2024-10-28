#include "iter.hpp"

int	main() {
	int intArray[] = {1, 2, 3, 4, 5};
	float floatArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	std::string stringArray[] = {"one", "two", "three", "four", "five"};

	std::cout << "INTEGER ARRAY:" << std::endl;
	iter(intArray, 5, print);
	std::cout << "Sum one:" << std::endl;
	iter(intArray, 5, sumOne);
	iter(intArray, 5, print);

	std::cout << "FLOAT ARRAY:" << std::endl;
	iter(floatArray, 5, print);
	std::cout << "Sum one:" << std::endl;
	iter(floatArray, 5, sumOne);
	iter(floatArray, 5, print);

	std::cout << "STRING ARRAY:" << std::endl;
	iter(stringArray, 5, print);
	std::cout << "Append:" << std::endl;
	iter(stringArray, 5, append);
	iter(stringArray, 5, print);

	return 0;
}