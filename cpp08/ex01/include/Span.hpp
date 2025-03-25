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
	void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);

	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;

	void fillSpan();
	void randomizeSpan(int max = RAND_MAX - 1);

	unsigned int size() const;
	std::vector<int> &getRange();

private:
	std::vector<int> _range;
	unsigned int _size;
};

std::ostream &operator<<(std::ostream &out, Span &span);

#endif