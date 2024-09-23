#include "Fixed.hpp"
#include "Point.hpp"

int	main(void)
{
	//triangle abc sides
	Point a(0, 0);
	Point b(3.0f, 0);
	Point c(3.0f, 4.0f);

	//points to check
	Point p(-1.7f, 1.0f);
	Point q(2.0f, 2.0f);
	Point r(3.0f, 4.0f);
	Point s(4.0f, 5.0f);

	bool resultP = bsp(a, b, c, p);
	bool resultQ = bsp(a, b, c, q);
	bool resultR = bsp(a, b, c, r);
	bool resultS = bsp(a, b, c, s);

	std::cout << "Is the point 'p' inside the triagle abc?\n" << (resultP ? "Yes" : "No") << '\n';
	std::cout << "Is the point 'q' inside the triagle abc?\n" << (resultQ ? "Yes" : "No") << '\n';
	std::cout << "Is the point 'r' inside the triagle abc?\n" << (resultR ? "Yes" : "No") << '\n';
	std::cout << "Is the point 's' inside the triagle abc?\n" << (resultS ? "Yes" : "No") << '\n';

	return (0);
}
