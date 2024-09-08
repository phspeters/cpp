#include "Fixed.hpp"
#include "Point.hpp"

int	main(void)
{
	Point a(1.1f, 2.2f);
	Point b(3.3f, 4.4f);
	Point c(5.5f, 6.6f);

	std::cout << bsp(a, b, c, Point(7.7f, 8.8f)) << std::endl;

	return (0);
}