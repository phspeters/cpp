#include "Functions.hpp"
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int	main() {
	
	std::cout << "TEST 1 - IDENTIFYING CLASSES BY POINTER:\n\n";
	
	std::cout << "Class A:\n";
	Base *aPtr = new A;
	identify(aPtr);
	delete aPtr;
	std::cout << "\n";

	std::cout << "Class B:\n";
	Base *bPtr = new B;
	identify(bPtr);
	delete bPtr;
	std::cout << "\n";

	std::cout << "Class C:\n";
	Base *cPtr = new C;
	identify(cPtr);
	delete cPtr;
	std::cout << "\n";

	std::cout << "\nTEST 2 - IDENTIFYING CLASSES BY REFERENCE:\n\n";
	
	std::cout << "Class A:\n";
	A aRef;
	identify(aRef);
	std::cout << "\n";

	std::cout << "Class B:\n";
	B bRef;
	identify(bRef);
	std::cout << "\n";

	std::cout << "Class C:\n";
	C cRef;
	identify(cRef);
	std::cout << "\n";

	std::cout << "\nTEST 3 - IDENTIFYING RANDOM CLASSES:\n\n";
	Base *base;
	for (int i = 0; i < 6; i++) {
		base = generate();
		identify(base);
		identify(*base);
		delete base;
		std::cout << "\n";
	}
	return (0);
}
