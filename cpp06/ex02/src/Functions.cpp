#include "Functions.hpp"

Base	*generate(void) {
	static bool	seeded = false;
	if (!seeded) {
		srand(time(NULL));
		seeded = true;
	}

	int		random = rand() % 3;
	switch (random) {
	case 0:
		std::cout << "A class generated\n";
		return (new A);
		break;
	case 1:
		std::cout << "B class generated\n";
		return (new B);
		break;
	case 2:
		std::cout << "C class generated\n";
		return (new C);
		break;
	default:
		std::cerr << "Error: generate failed\n";
		return (NULL);
		break;
	}
}

void	identify(Base* p) {
	std::cout << "Identifying class by pointer: ";
	if (dynamic_cast<A*>(p)) {
		std::cout << "is type: A\n";
	}
	else if (dynamic_cast<B*>(p)) {
		std::cout << "is type: B\n";
	}
	else if (dynamic_cast<C*>(p)) {
		std::cout << "is type: C\n";
	}
	else {
		std::cout << "Unknown class\n";
	}
}

void identify(Base &p) {

	std::cout << "Identifying class by reference: ";
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "is type: A\n";
		return ;
	} catch (std::exception&) {}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "is type: B\n";
		return ;
	} catch (std::exception&) {}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "is type: C\n";
		return ;
	} catch (std::exception&) {}
}
