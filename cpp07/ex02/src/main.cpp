#include "Array.hpp"
#include "Array.tpp"
#include <ctime>
#include <cstdlib>

# define MAX_VAL 750

int subject_tests(void) {
	std::cout << "SUBJECT TESTS\n\n";

	Array<int> numbers(MAX_VAL);
	int *mirror = new int[MAX_VAL];
	srand(time(NULL));
	
	for (int i = 0; i < MAX_VAL; i++) {
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}

	// SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++) {
		if (mirror[i] != numbers[i]) {
			std::cerr << "didn't save the same value!!" << '\n';
			return (1);
		}
	}

	try {
		numbers[-2] = 0;
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
	}

	try	{
		numbers[MAX_VAL] = 0;
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++) {
		numbers[i] = rand();
	}

	delete[] mirror;
	return (0);
}

int other_tests(void) {
	std::cout << "OTHER TESTS\n\n";
	
	std::cout << "... Testing empty array ...\n";
	Array<int> empty;

	std::cout << "empty: " << empty << '\n';
	std::cout << '\n';

	std::cout << "... Testing assignment operator = ...\n";
	Array<int> numbers(5);
	Array<int> mirror(5);

	for (int i = 0; i < 5; i++) {
		const int value = rand() % 1000;
		numbers[i] = value;
	}
	std::cout << '\n';

	std::cout << "... Before assignment ...\n";
	std::cout << "numbers: " << numbers << '\n';
	std::cout << "mirror: " << mirror << '\n';
	std::cout << '\n';

	std::cout << "... Assigning numbers to mirror ...\n";
	mirror = numbers;
	std::cout << '\n';

	std::cout << "... After assignment ...\n";
	std::cout << "numbers: " << numbers << '\n';
	std::cout << "mirror: " << mirror << '\n';
	std::cout << '\n';

	std::cout << "... Changing mirror array ...\n";
	for (int i = 0; i < 5; i++) {
		mirror[i] = 42;
	}
	std::cout << '\n';

	std::cout << "... After changes ...\n";
	std::cout << "numbers: " << numbers << '\n';
	std::cout << "mirror: " << mirror << '\n';
	std::cout << '\n';

	std::cout << "... Testing copy constructor ...\n";
	Array<int> copy(numbers);
	std::cout << "copy: " << copy << '\n';
	std::cout << '\n';

	std::cout << "... Testing size() ...\n";
	std::cout << "numbers.size(): " << numbers.size() << '\n';
	std::cout << "copy.size(): " << copy.size() << '\n';
	std::cout << "empty.size(): " << empty.size() << '\n';
	std::cout << '\n';

	std::cout << "... Testing access operator [] ...\n";
	std::cout << "copy[0]: " << copy[0] << '\n';
	std::cout << "copy[3]: " << copy[3] << '\n';
	try {
		std::cout << "copy[5]: " << copy[5] << '\n';
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
	}

	return (0);
}

int	main(void) {
	subject_tests();
	std::cout << "\n--------------------------------------------------------------------------------\n\n";
	other_tests();
	return (0);
}