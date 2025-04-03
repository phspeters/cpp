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
		std::stack<T, Container>::operator=(other);
		return (*this);
	};

	typedef typename std::stack<T, Container>::container_type::iterator iterator;
	typedef typename std::stack<T, Container>::container_type::const_iterator const_iterator;

	iterator begin() { return std::stack<T, Container>::c.begin(); };
	iterator end() { return std::stack<T, Container>::c.end(); };
	const_iterator begin() const { return std::stack<T, Container>::c.begin(); };
	const_iterator end() const { return std::stack<T, Container>::c.end(); };
};

template <typename T, typename Container>
std::ostream &operator<<(std::ostream &out, MutantStack<T, Container> const &mstack) {
	typename MutantStack<T, Container>::const_iterator it = mstack.begin();
	typename MutantStack<T, Container>::const_iterator ite = mstack.end();

	out << "{ ";
	if (it != ite) {
		out << *it;
		while (++it != ite) {
			out << ", " << *it;
		}
	}
	out << " }";
	
	return (out);
}

#endif