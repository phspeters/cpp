#include "Fixed.hpp"

int	main(void)
{
	std::cout << "DEFAULT CONSTRUCTOR:" << std::endl;
	Fixed a;
	std::cout << std::endl;

	std::cout << "COPY CONSTRUCTOR:" << std::endl;
	Fixed b(a);
	std::cout << std::endl;

	std::cout << "DEFAULT CONSTRUCTOR + ASSIGNMENT OPERATOR:" << std::endl;
	Fixed c;
	c = b;
	std::cout << std::endl;

	std::cout << "GET RAW BITS:" << std::endl;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	std::cout << std::endl;

	std::cout << "SET RAW BITS:" << std::endl;
	a.setRawBits(42);
	b.setRawBits(21);
	c.setRawBits(84);
	std::cout << std::endl;

	std::cout << "GET RAW BITS:" << std::endl;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	std::cout << std::endl;

	std::cout << "DESTRUCTOR:" << std::endl;
	return (0);
}