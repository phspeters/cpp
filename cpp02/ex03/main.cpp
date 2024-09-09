#include "Fixed.hpp"
#include "Point.hpp"

int	main(void)
{
	Point a(0, 0);
	Point b(3.0f, 0);
	Point c(3.0f, 4.0f);

	std::cout << bsp(a, b, c, Point(1.7f, 1.0f)) << std::endl;

	return (0);
}
