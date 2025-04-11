#include "Span.hpp"

Span::Span() : _range(), _size(0) {}

Span::Span(unsigned int n) : _range(), _size(n) {}

Span::Span(const Span &src) : _range(src._range), _size(src._size) {}

Span::~Span() {}

Span &Span::operator=(const Span &other) {
    if (this != &other) {
        _range = other._range;
        _size = other._size;
    }

    return *this;
}

void Span::addNumber(int n) {
    if (_range.size() >= size()) {
        throw std::overflow_error("Span is full: cannot add more numbers");
    }

    _range.push_back(n);
}

unsigned int Span::shortestSpan() const {
    if (_range.size() < 2) {
        throw std::underflow_error(
            "Span is too short: not enough elements to calculate a span");
    }

    std::vector<int> difference = _range;
    std::sort(difference.begin(), difference.end());
    std::adjacent_difference(difference.begin(), difference.end(),
                             difference.begin());

    int shortest = *std::min_element(difference.begin() + 1, difference.end());

    return shortest;
}

unsigned int Span::longestSpan() const {
    if (_range.size() < 2) {
        throw std::underflow_error(
            "Span is too short: not enough elements to calculate a span");
    }

    long largest = *std::max_element(_range.begin(), _range.end());
    long smallest = *std::min_element(_range.begin(), _range.end());

    return largest - smallest;
}

void Span::fillSpan() {
    for (std::size_t i = _range.size(); i < size(); ++i) {
        _range.push_back(i);
    }
}

void Span::randomizeSpan(int max) {
    _generateRandomSeedOnce();

    if (max <= 0) {
        max = RAND_MAX;
    }

    for (std::vector<int>::iterator i = _range.begin(); i != _range.end();
         ++i) {
        int randomValue =
            static_cast<int>(static_cast<double>(std::rand()) / RAND_MAX * max);

        *i = (std::rand() & 1) ? randomValue : -randomValue;
    }
}

unsigned int Span::size() const { return _size; }

std::vector<int> &Span::getRange() { return _range; }

void Span::_generateRandomSeedOnce() {
    static bool seedGenerated = false;

    if (seedGenerated) {
        return;
    }

    std::srand(static_cast<unsigned int>(std::time(0)));
    seedGenerated = true;
}

std::ostream &operator<<(std::ostream &out, Span &span) {
    std::vector<int>::const_iterator it = span.getRange().begin();
    std::vector<int>::const_iterator ite = span.getRange().end();

    out << "{";
    if (it != ite) {
        out << *it;
        while (++it != ite) {
            out << ", " << *it;
        }
    }
    out << "}";

    return out;
}
