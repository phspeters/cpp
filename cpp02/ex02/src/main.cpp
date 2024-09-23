#include "Fixed.hpp"

int	main(void)
{
	std::cout << std::boolalpha;

	Fixed a;
	Fixed b(5.05f);
	Fixed const c(10);
	Fixed d(b);
	std::cout << '\n';

	std::cout << "INITIAL STATE:\n";
	std::cout << "'a' is " << a << std::endl;
	std::cout << "'b' is " << b << std::endl;
	std::cout << "'c' is " << c << std::endl;
	std::cout << "'d' is " << d << std::endl;
	std::cout << '\n';

	std::cout << "ASSIGNMENT OPERATORS:\n";
	d = c;
	std::cout << "'c' is " << c << " and 'd' is " << d << std::endl;
	std::cout << '\n';

	std::cout << "COMPARISON OPERATORS:\n";
	std::cout << "'c' is " << c << " and 'd' is " << d << std::endl;
	std::cout << '\n';

	std::cout << "c == d\n";
	std::cout << (c == d) << std::endl;
	std::cout << "c != d\n";
	std::cout << (c != d) << std::endl;
	std::cout << "c > d\n";
	std::cout << (c > d) << std::endl;
	std::cout << "c < d\n";
	std::cout << (c < d) << std::endl;
	std::cout << "c >= d\n";
	std::cout << (c >= d) << std::endl;
	std::cout << "c <= d\n";
	std::cout << (c <= d) << std::endl;
	std::cout << '\n';

	std::cout << "ARITHMETIC OPERATORS:\n";
	std::cout << "'b' is " << b << " and 'c' is " << c << std::endl;
	std::cout << '\n';

	std::cout << "b + c\n";
	std::cout << (b + c) << std::endl;
	std::cout << "b - c\n";
	std::cout << (b - c) << std::endl;
	std::cout << "b * c\n";
	std::cout << (b * c) << std::endl;
	std::cout << "b / c\n";
	std::cout << (b / c) << std::endl;
	std::cout << '\n';

	std::cout << "INCREMENT OPERATORS:\n";
	std::cout << "a\n";
	std::cout << a << std::endl;
	std::cout << "++a\n";
	std::cout << ++a << std::endl;
	std::cout << "a\n";
	std::cout << a << std::endl;
	std::cout << "a++\n";
	std::cout << a++ << std::endl;
	std::cout << "a\n";
	std::cout << a << std::endl;
	std::cout << '\n';

	std::cout << "DECREMENT OPERATORS:\n";
	std::cout << "b\n";
	std::cout << b << std::endl;
	std::cout << "--b\n";
	std::cout << --b << std::endl;
	std::cout << "b\n";
	std::cout << b << std::endl;
	std::cout << "b--\n";
	std::cout << b-- << std::endl;
	std::cout << "b\n";
	std::cout << b << std::endl;
	std::cout << '\n';

	std::cout << "MIN FUNCTIONS\n";
	std::cout << "a is " << a << " and b is " << b << std::endl;
	std::cout << "Fixed::min(a, b)\n";
	std::cout << Fixed::min(a, b) << std::endl;
	std::cout << '\n';

	std::cout << "c is " << c << " and d is " << d << std::endl;
	std::cout << "Fixed::min(c, d)\n";
	std::cout << Fixed::min(c, d) << std::endl;
	std::cout << '\n';

	std::cout << "MAX FUNCTIONS\n";
	std::cout << "a is " << a << " and b is " << b << std::endl;
	std::cout << "Fixed::max(a, b)\n";
	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << '\n';
	
	std::cout << "c is " << c << " and d is " << d << std::endl;
	std::cout << "Fixed::max(c, d)\n";
	std::cout << Fixed::max(c, d) << std::endl;
	std::cout << '\n';

	return (0);
}