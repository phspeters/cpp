#include "Fixed.hpp"

int	main(void)
{
	std::cout << std::boolalpha;

	std::cout << "CONSTRUCTORS:" << std::endl;
	Fixed a;
	Fixed b(5.05f);
	Fixed const c(10);
	Fixed d(b);
	std::cout << std::endl;

	std::cout << "INITIAL STATE:" << std::endl;
	std::cout << "'a' is " << a << std::endl;
	std::cout << "'b' is " << b << std::endl;
	std::cout << "'c' is " << c << std::endl;
	std::cout << "'d' is " << d << std::endl;
	std::cout << std::endl;

	std::cout << "ASSIGNMENT OPERATORS:" << std::endl;
	d = c;
	std::cout << "'c' is " << c << " and 'd' is " << d << std::endl;
	std::cout << std::endl;

	std::cout << "COMPARISON OPERATORS:" << std::endl;
	std::cout << "'c' is " << c << " and 'd' is " << d << std::endl;
	std::cout << "c == d" << std::endl;
	std::cout << (c == d) << std::endl;
	std::cout << "c != d" << std::endl;
	std::cout << (c != d) << std::endl;
	std::cout << "c > d" << std::endl;
	std::cout << (c > d) << std::endl;
	std::cout << "c < d" << std::endl;
	std::cout << (c < d) << std::endl;
	std::cout << "c >= d" << std::endl;
	std::cout << (c >= d) << std::endl;
	std::cout << "c <= d" << std::endl;
	std::cout << (c <= d) << std::endl;
	std::cout << std::endl;

	std::cout << "ARITHMETIC OPERATORS:" << std::endl;
	std::cout << "'b' is " << b << " and 'c' is " << c << std::endl;
	std::cout << "b + c" << std::endl;
	std::cout << (b + c) << std::endl;
	std::cout << "b - c" << std::endl;
	std::cout << (b - c) << std::endl;
	std::cout << "b * c" << std::endl;
	std::cout << (b * c) << std::endl;
	std::cout << "b / c" << std::endl;
	std::cout << (b / c) << std::endl;
	std::cout << std::endl;

	std::cout << "INCREMENT OPERATORS:" << std::endl;
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
	std::cout << std::endl;

	std::cout << "DECREMENT OPERATORS:" << std::endl;
	std::cout << "b" << std::endl;
	std::cout << b << std::endl;
	std::cout << "--b" << std::endl;
	std::cout << --b << std::endl;
	std::cout << "b" << std::endl;
	std::cout << b << std::endl;
	std::cout << "b--" << std::endl;
	std::cout << b-- << std::endl;
	std::cout << "b" << std::endl;
	std::cout << b << std::endl;
	std::cout << std::endl;

	std::cout << "MIN FUNCTIONS" << std::endl;
	std::cout << "a is " << a << " and b is " << b << std::endl;
	std::cout << "Fixed::min(a, b)" << std::endl;
	std::cout << Fixed::min(a, b) << std::endl;
	std::cout << "c is " << c << " and d is " << d << std::endl;
	std::cout << "Fixed::min(c, d)" << std::endl;
	std::cout << Fixed::min(c, d) << std::endl;
	std::cout << std::endl;

	std::cout << "MAX FUNCTIONS" << std::endl;
	std::cout << "a is " << a << " and b is " << b << std::endl;
	std::cout << "Fixed::max(a, b)" << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << "c is " << c << " and d is " << d << std::endl;
	std::cout << "Fixed::max(c, d)" << std::endl;
	std::cout << Fixed::max(c, d) << std::endl;
	std::cout << std::endl;

	std::cout << "Destructors:" << std::endl;
	return (0);
}