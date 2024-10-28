#include "Fixed.hpp"

int	main() {
	std::cout << "DEFAULT CONSTRUCTOR:\n";
	Fixed a;
	std::cout << '\n';

	std::cout << "INT CONSTRUCTOR:\n";
	Fixed const b(10);
	std::cout << '\n';

	std::cout << "FLOAT CONSTRUCTOR:\n";
	Fixed const c(42.42f);
	std::cout << '\n';

	std::cout << "COPY CONSTRUCTOR:\n";
	Fixed const d(b);
	std::cout << '\n';

	std::cout << "ASSIGNMENT OPERATOR:\n";
	a = Fixed(1234.4321f);
	std::cout << '\n';

	std::cout << "PRINTING VALUES AND FIXED POINT:\n";
	std::cout << "a is " << a << '\n';
	std::cout << "b is " << b << '\n';
	std::cout << "c is " << c << '\n';
	std::cout << "d is " << d << '\n';
	std::cout << '\n';

	std::cout << "PRINTING VALUES AS INTEGER:\n";
	std::cout << "a is " << a.toInt() << " as integer\n";
	std::cout << "b is " << b.toInt() << " as integer\n";
	std::cout << "c is " << c.toInt() << " as integer\n";
	std::cout << "d is " << d.toInt() << " as integer\n";
	std::cout << '\n';
	
	std::cout << "DESTRUCTORS:\n";
	return (0);
}