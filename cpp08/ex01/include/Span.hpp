#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <exception>
# include <ctime>
# include <cstdlib>

class Span {
public:
	Span();
	Span(unsigned int n);
	Span(Span const &src);
	~Span();
	
	Span &operator=(Span const &rhs);

	void addNumber(int n);
	int shortestSpan();
	int longestSpan();
	unsigned int size() const;

	void randomizeSpan();

	std::vector<int> _numbers;

private:
	unsigned int _size;
};

std::ostream &operator<<(std::ostream &out, Span const &span);

#endif