#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <stdexcept>
# include <ctime>
# include <cstdlib>
# include <numeric>

class Span {
public:
	Span();
	Span(unsigned int n);
	Span(Span const &src);
	~Span();
	
	Span &operator=(Span const &rhs);

	void addNumber(int n);
	template <typename Iterator> void addRange(Iterator begin, Iterator end);

	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;

	void fillSpan();
	void randomizeSpan(int max = RAND_MAX - 1);
	
	unsigned int size() const;
	std::vector<int> &getRange();
	
	private:
	void _generateRandomSeedOnce();
	std::vector<int> _range;
	unsigned int _size;
};

std::ostream &operator<<(std::ostream &out, Span &span);

template <typename Iterator>
void Span::addRange(Iterator begin, Iterator end) {
	if (_range.size() + std::distance(begin, end) > size()) {
		throw std::overflow_error("Span cannot hold this range: exceeding capacity");
	}

	_range.insert(_range.end(), begin, end);
}

#endif