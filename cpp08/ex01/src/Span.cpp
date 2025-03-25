#include "Span.hpp"

Span::Span() : _range(), _size(0) {
	std::srand(static_cast<unsigned int>(std::time(0)));
}

Span::Span(unsigned int n) : _range(), _size(n) {
	std::srand(static_cast<unsigned int>(std::time(0)));
}

Span::Span(Span const &src) : _range(src._range), _size(src._size) {}

Span::~Span() {}

Span &Span::operator=(Span const &other) {
	if (this != &other) {
		_range = other._range;
		_size = other._size;
	}

	return (*this);
}

void Span::addNumber(int n) {
	if (_range.size() >= size())
		throw std::overflow_error("Span is full: cannot add more numbers");

	_range.push_back(n);
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (_range.size() + std::distance(begin, end) > size()) {
		throw std::overflow_error("Span cannot hold this range: exceeding capacity");
	}

	_range.insert(_range.end(), begin, end);
}

unsigned int Span::shortestSpan() const {
	if (_range.size() < 2) {
		throw std::underflow_error("Span is too short: not enough elements to calculate a span");
	}

	std::vector<int> difference = _range;
	std::sort(difference.begin(), difference.end());
	std::adjacent_difference(difference.begin(), difference.end(), difference.begin());

	int shortest = *std::min_element(difference.begin() + 1, difference.end());

	return (shortest);
}

unsigned int Span::longestSpan() const {
	if (_range.size() < 2) {
		throw std::underflow_error("Span is too short: not enough elements to calculate a span");
	}

	long largest = *std::max_element(_range.begin(), _range.end());
	long smallest = *std::min_element(_range.begin(), _range.end());

	return (largest - smallest);
}

void Span::fillSpan() {
	for (std::size_t i = _range.size(); i < size(); ++i) {
		_range.push_back(i);
	}
}

void Span::randomizeSpan(int max) {
	std::srand(std::time(0));

	for (std::vector<int>::iterator i = _range.begin(); i != _range.end(); ++i) {
		*i = std::rand() % max;
		if (std::rand() % 2) {
			*i *= -1;
		}
	}
}

unsigned int Span::size() const {
	return (_size);
}

std::vector<int> &Span::getRange() {
	return (_range);
}

std::ostream &operator<<(std::ostream &out, Span &span) {
	out << "{";

	for (std::vector<int>::const_iterator i = span.getRange().begin(); i != span.getRange().end(); ++i) {
		out << *i;
		if (i + 1 != span.getRange().end()) {
			out << ", ";
		}
	}

	out << "}";

	return (out);
}