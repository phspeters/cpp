#include "Fixed.hpp"

int	main(void)
{
	std::cout << "DEFAULT CONSTRUCTOR:\n";
	Fixed a;
	std::cout << '\n';

	std::cout << "COPY CONSTRUCTOR:\n";
	Fixed b(a);
	std::cout << '\n';

	std::cout << "DEFAULT CONSTRUCTOR + ASSIGNMENT OPERATOR:\n";
	Fixed c;
	c = b;
	std::cout << '\n';

	std::cout << "GET RAW BITS:\n";
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	std::cout << '\n';

	std::cout << "SET RAW BITS:\n";
	a.setRawBits(42);
	b.setRawBits(21);
	c.setRawBits(84);
	std::cout << '\n';

	std::cout << "GET RAW BITS:\n";
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	std::cout << '\n';

	std::cout << "DESTRUCTOR:\n";
	return (0);
}