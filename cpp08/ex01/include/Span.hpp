#ifndef SPAN_HPP
# define SPAN_HPP

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
};

#endif