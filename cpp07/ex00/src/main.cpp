#include "whatever.hpp"

int	main() {
	std::cout << "TESTING INTEGERS\n";
	int a = 2;
	int b = 9;

	std::cout << "a = " << a << ", b = " << b << "\n";
	std::cout << "swap( a, b )\n";
	swap(a, b);
	std::cout << "a = " << a << ", b = " << b << "\n";
	std::cout << "min( a, b ) = " << ::min(a, b) << "\n";
	std::cout << "max( a, b ) = " << ::max(a, b) << "\n\n";

	std::cout << "TESTING STRINGS\n";
	std::string c = "Hello";
	std::string d = "World!";


	std::cout << "c = " << c << ", d = " << d << "\n";
	std::cout << "swap( c, d )\n";
	swap(c, d);
	std::cout << "c = " << c << ", d = " << d << "\n";
	std::cout << "min( c, d ) = " << ::min(c, d) << "\n";
	std::cout << "max( c, d ) = " << ::max(c, d) << "\n\n";

	std::cout << "TESTING DOUBLES\n";
	double	e = 42.42;
	double	f = 21.21;

	std::cout << "e = " << e << ", f = " << f << "\n";
	std::cout << "swap( e, f )\n";
	swap(e, f);
	std::cout << "e = " << e << ", f = " << f << "\n";
	std::cout << "min( e, f ) = " << ::min(e, f) << "\n";
	std::cout << "max( e, f ) = " << ::max(e, f) << "\n\n";

	std::cout << "TESTING STRUCTS\n";
	Data g;
	Data h;
	g.nbr = 42;
	h.nbr = 24;

	std::cout << "g.nbr = " << g.nbr << ", h.nbr = " << h.nbr << "\n";
	std::cout << "swap( g, h )\n";
	swap(g, h);
	std::cout << "g.nbr = " << g.nbr << ", h.nbr = " << h.nbr << "\n";
	std::cout << "min( g, h ) = " << ::min(g.nbr, h.nbr) << "\n";
	std::cout << "max( g, h ) = " << ::max(g.nbr, h.nbr) << "\n";

	return (0);
}