#include "Fixed.hpp"

int	main(void)
{
	std::cout << "Constructors:" << std::endl;
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << std::endl;

	std::cout << "Increment operators:" << std::endl;
	std::cout << "a" << std::endl;
	std::cout << a << std::endl;
	std::cout << "++a" << std::endl;
	std::cout << ++a << std::endl;
	std::cout << "a" << std::endl;
	std::cout << a << std::endl;
	std::cout << "a++" << std::endl;
	std::cout << a++ << std::endl;
	std::cout << "a" << std::endl;
	std::cout << a << std::endl;
	std::cout << "b" << std::endl;
	std::cout << b << std::endl;
	std::cout << std::endl;

	std::cout << "Fixed::max(a, b)" << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << std::endl;

	std::cout << "Destructors:" << std::endl;
	return (0);
}