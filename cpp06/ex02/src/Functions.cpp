#include "Functions.hpp"

Base	*generate(void) {

	static bool	seeded = false;
	if (!seeded)
	{
		srand(time(NULL));
		seeded = true;
	}

	int		random = rand() % 3;
	switch (random)
	{
	case 0:
		std::cout << "A class generated" << std::endl;
		return (new A);
		break;
	case 1:
		std::cout << "B class generated" << std::endl;
		return (new B);
		break;
	case 2:
		std::cout << "C class generated" << std::endl;
		return (new C);
		break;
	default:
		std::cerr << "Error: generate failed" << std::endl;
		return (NULL);
		break;
	}
}

void	identify(Base* p) {

	std::cout << "Identifying class by pointer: ";
	if (dynamic_cast<A*>(p))
		std::cout << "is type: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "is type: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "is type: C" << std::endl;
	else
		std::cout << "Unknown class" << std::endl;
}

void identify(Base &p) {

	std::cout << "Identifying class by reference: ";
    try {
		(void)dynamic_cast<A&>(p);
		std::cout << "is type: A" << std::endl;
		return;
    } catch (std::exception&) {}

    try {
		(void)dynamic_cast<B&>(p);
		std::cout << "is type: B" << std::endl;
		return;
    } catch (std::exception&) {}

    try {
		(void)dynamic_cast<C&>(p);
		std::cout << "is type: C" << std::endl;
		return;
    } catch (std::exception&) {}
}
