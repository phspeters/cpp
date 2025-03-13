#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe const & src) {
	*this = src;
}

PmergeMe & PmergeMe::operator=(PmergeMe const & rhs) {
	(void)rhs;
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::sort_vec(std::vector<int>& vec) {
	_merge_insertion_sort<std::vector<int> >(vec, 1);
}

void PmergeMe::sort_deque(std::deque<int>& deque) {
    _merge_insertion_sort<std::deque<int> >(deque, 1);
}

int PmergeMe::nbr_of_comps = 0;