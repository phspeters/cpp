#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template < typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
public:
	MutantStack() : std::stack<T, Container>() {};
	MutantStack(MutantStack const &other) : std::stack<T, Container>(other) {};
	~MutantStack() {};

	MutantStack<T, Container> &operator=(MutantStack const &other) {
		if (this != &other) {
			std::stack<T, Container>::operator=(other);
		}
		return (*this);
	};

	typedef typename std::stack<T, Container>::container_type::iterator iterator;
	typedef typename std::stack<T, Container>::container_type::const_iterator const_iterator;

	iterator begin() { return std::stack<T, Container>::c.begin(); };
	iterator end() { return std::stack<T, Container>::c.end(); };
	const_iterator begin() const { return std::stack<T, Container>::c.begin(); };
	const_iterator end() const { return std::stack<T, Container>::c.end(); };
};

std::ostream &operator<<(std::ostream &out, MutantStack<int> const &mstack) {
	MutantStack<int>::const_iterator it = mstack.begin();
	MutantStack<int>::const_iterator ite = mstack.end();

	out << "{ ";
	while (it != ite) {
		out << *it;
		if (it + 1 != ite) {
			out << ", ";
		}
		++it;
	}
	out << " }";
	
	return (out);
}

#endif