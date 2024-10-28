#include "Functions.hpp"
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int	main() {
	
	std::cout << "Test 1 - Identifying classes by pointer:\n\n";
	
	std::cout << "Class A:\n";
	Base *aPtr = new A;
	identify(aPtr);
	delete aPtr;

	std::cout << "Class B:\n";
	Base *bPtr = new B;
	identify(bPtr);
	delete bPtr;

	std::cout << "Class C:\n";
	Base *cPtr = new C;
	identify(cPtr);
	delete cPtr;

	std::cout << "\nTest 2 - Identifying classes by reference:\n\n";
	
	std::cout << "Class A:\n";
	A aRef;
	identify(aRef);

	std::cout << "Class B:\n";
	B bRef;
	identify(bRef);

	std::cout << "Class C:\n";
	C cRef;
	identify(cRef);

	std::cout << "\nTest 3 - Identifying random classes:\n\n";
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
