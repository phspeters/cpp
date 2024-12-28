#include "Span.hpp"

Span::Span() : _numbers(0) {}

Span::Span(unsigned int n) : _numbers(n) {}

Span::Span(Span const &src) : _numbers(src._numbers) {}

Span::~Span() {}

Span &Span::operator=(Span const &other) {
	if (this != &other)
		_numbers = other._numbers;

	return (*this);
}

void Span::addNumber(int n) {
	if (_numbers.size() == _numbers.capacity())
		throw std::overflow_error("Span is full");
	_numbers.push_back(n);
}

int Span::shortestSpan() {
	if (_numbers.size() < 2)
		throw std::underflow_error("Span is too short");

	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());

	int shortest = sorted[1] - sorted[0];
	for (std::vector<int>::iterator i = sorted.begin(); i + 1 != sorted.end(); ++i) {
		int diff = *(i + 1) - *i;
		if (diff < shortest)
			shortest = diff;
	}

	return (shortest);
}

int Span::longestSpan() {
	if (_numbers.size() < 2)
		throw std::underflow_error("Span is too short");

	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());

	return (sorted.back() - sorted.front());
}

unsigned int Span::size() const {
	return (_numbers.size());
}

void Span::randomizeSpan() {
	std::srand(std::time(0));
	for (std::vector<int>::iterator i = _numbers.begin(); i != _numbers.end(); ++i)
		*i = std::rand();
}

std::ostream &operator<<(std::ostream &out, Span const &span) {
	out << "{";
	for (std::vector<int>::const_iterator i = span._numbers.begin(); i != span._numbers.end(); ++i) {
		out << *i;
		if (i + 1 != span._numbers.end())
			out << ", ";
	}
	out << "}";
	return (out);
}