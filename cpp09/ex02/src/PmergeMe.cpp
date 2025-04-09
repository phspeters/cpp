#include "PmergeMe.hpp"

int PmergeMe::comparison_counter = 0;

std::size_t PmergeMe::_jacobsthal_cache[62] = {0};

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe const & rhs) {
	(void)rhs;
}

PmergeMe & PmergeMe::operator=(PmergeMe const & rhs) {
	(void)rhs;
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::sort_vec(std::vector<int>& vec) {
	comparison_counter = 0;
	_merge_insertion_sort<std::vector<int>, std::vector< std::vector<int>::iterator> >(vec, 1);
}

void PmergeMe::sort_deque(std::deque<int>& deque) {
	comparison_counter = 0;
	_merge_insertion_sort<std::deque<int>, std::deque< std::deque<int>::iterator> >(deque, 1);
}

std::size_t PmergeMe::_calculate_jacobsthal_number(std::size_t n) {
	if (std::size_t cache = _jacobsthal_cache[n])
		return cache;

	std::size_t result = round((pow(2, n + 1) + pow(-1, n)) / 3);
	_jacobsthal_cache[n] = result;

	return result;
}
