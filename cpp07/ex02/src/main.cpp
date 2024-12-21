#include "Array.hpp"
#include "Array.tpp"
#include <ctime>
#include <cstdlib>

# define MAX_VAL 750

int subject_tests(void) {
	std::cout << "SUBJECT TESTS" << '\n';

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
	std::cout << "OTHER TESTS" << '\n';
	Array<int> numbers(5);
	Array<int> mirror(5);

	for (int i = 0; i < 5; i++) {
		const int value = rand() % 1000;
		numbers[i] = value;
	}

	std::cout << "numbers: " << numbers << '\n';
	std::cout << "mirror: " << mirror << '\n';
	std::cout << '\n';

	mirror = numbers;

	std::cout << "numbers: " << numbers << '\n';
	std::cout << "mirror: " << mirror << '\n';
	std::cout << '\n';

	for (int i = 0; i < 5; i++) {
		numbers[i] = 42;
	}

	std::cout << "numbers: " << numbers << '\n';
	std::cout << "mirror: " << mirror << '\n';
	std::cout << '\n';

	return (0);
}

int	main(void) {
	subject_tests();
	std::cout << '\n';
	other_tests();
	return (0);
}