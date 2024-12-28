#include "Span.hpp"

int	main(void) {
	Span span(50000);

	std::cout << span._numbers.size() << std::endl;
	span.randomizeSpan();
	std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
	std::cout << "Longest span: " << span.longestSpan() << std::endl;
}
