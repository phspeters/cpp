#include "Fixed.hpp"

int	main() {
	std::cout << std::boolalpha;

	Fixed a;
	Fixed b(5.05f);
	Fixed const c(10);
	Fixed const d(b);

	std::cout << "INITIAL STATE:\n";
	std::cout << "'a' is " << a << '\n';
	std::cout << "'b' is " << b << '\n';
	std::cout << "'c' is " << c << '\n';
	std::cout << "'d' is " << d << '\n';
	std::cout << '\n';

	std::cout << "COMPARISON OPERATORS:\n";
	std::cout << "'c' is " << c << " and 'd' is " << d << '\n';
	std::cout << '\n';
	
	std::cout << "c == d\n";
	std::cout << (c == d) << '\n';
	std::cout << "c != d\n";
	std::cout << (c != d) << '\n';
	std::cout << "c > d\n";
	std::cout << (c > d) << '\n';
	std::cout << "c < d\n";
	std::cout << (c < d) << '\n';
	std::cout << "c >= d\n";
	std::cout << (c >= d) << '\n';
	std::cout << "c <= d\n";
	std::cout << (c <= d) << '\n';
	std::cout << '\n';

	std::cout << "ARITHMETIC OPERATORS:\n";
	std::cout << "'b' is " << b << " and 'c' is " << c << '\n';
	std::cout << '\n';

	std::cout << "b + c\n";
	std::cout << (b + c) << '\n';
	std::cout << "b - c\n";
	std::cout << (b - c) << '\n';
	std::cout << "b * c\n";
	std::cout << (b * c) << '\n';
	std::cout << "b / c\n";
	std::cout << (b / c) << '\n';
	std::cout << '\n';

	std::cout << "INCREMENT OPERATORS:\n";
	std::cout << "a\n";
	std::cout << a << '\n';
	std::cout << "++a\n";
	std::cout << ++a << '\n';
	std::cout << "a\n";
	std::cout << a << '\n';
	std::cout << "a++\n";
	std::cout << a++ << '\n';
	std::cout << "a\n";
	std::cout << a << '\n';
	std::cout << '\n';

	std::cout << "DECREMENT OPERATORS:\n";
	std::cout << "b\n";
	std::cout << b << '\n';
	std::cout << "--b\n";
	std::cout << --b << '\n';
	std::cout << "b\n";
	std::cout << b << '\n';
	std::cout << "b--\n";
	std::cout << b-- << '\n';
	std::cout << "b\n";
	std::cout << b << '\n';
	std::cout << '\n';

	std::cout << "MIN FUNCTIONS\n";
	std::cout << "a is " << a << " and b is " << b << '\n';
	std::cout << "Fixed::min(a, b)\n";
	std::cout << Fixed::min(a, b) << '\n';
	std::cout << '\n';

	std::cout << "c is " << c << " and d is " << d << '\n';
	std::cout << "Fixed::min(c, d)\n";
	std::cout << Fixed::min(c, d) << '\n';
	std::cout << '\n';

	std::cout << "MAX FUNCTIONS\n";
	std::cout << "a is " << a << " and b is " << b << '\n';
	std::cout << "Fixed::max(a, b)\n";
	std::cout << Fixed::max(a, b) << '\n';
	std::cout << '\n';
	
	std::cout << "c is " << c << " and d is " << d << '\n';
	std::cout << "Fixed::max(c, d)\n";
	std::cout << Fixed::max(c, d) << '\n';
	std::cout << '\n';

	return (0);
}