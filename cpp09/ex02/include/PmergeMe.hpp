#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>

template <typename T>
class PmergeMe {
public:
	PmergeMe();
	PmergeMe(PmergeMe const & src);
	~PmergeMe();
	PmergeMe & operator=(PmergeMe const & rhs);

private:
};

#endif