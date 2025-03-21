#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <cmath>
# include <algorithm>
# include <deque>
# include <vector>

template <typename Iterator>
bool _comp(Iterator lv, Iterator rv);

template <typename Iterator> 
Iterator get_iterator_at_offset(Iterator it, int steps);

template <typename Iterator>
void _swap_with_next_pair(Iterator rightmost_element_it, int pair_group_size);

template <typename Container, typename Chain>
void print_chain(Chain& chain, int pair_group_size);

template <typename Container>
void print_container(Container& container);

class PmergeMe
{
public:
	PmergeMe();
	PmergeMe(const PmergeMe& pm);
	PmergeMe& operator=(const PmergeMe& pm);
	~PmergeMe();

	static int comparison_counter;
	
	void sort_vec(std::vector<int>& vec);
	void sort_deque(std::deque<int>& deque);

private:
	std::size_t _jacobsthal_number(std::size_t n);
	static std::size_t _jacobsthal_cache[62];

	template <typename Container, typename Chain> void _merge_insertion_sort(Container& container, int pair_group_size);
	template <typename Container, typename Chain> void _merge_phase(Container& container, int pair_group_size);
	template <typename Container, typename Chain> void _create_chains(Container& container, int pair_group_size, Chain& main, Chain& pend);
	template <typename Container, typename Chain> std::size_t _optimized_insertion(Chain& main, Chain& pend);
	template <typename Container, typename Chain> void _insert_remaining(std::size_t container_size, int pair_group_size, Chain& main, Chain& pend, std::size_t processed_pend_elements);
	template <typename Container, typename Chain> void _update_container(Container& container, Chain& main, int pair_group_size);
};

template <typename Container, typename Chain>
void PmergeMe::_merge_insertion_sort(Container& container, int pair_group_size) {
	_merge_phase<Container, Chain>(container, pair_group_size);

	Chain main;
	Chain pend;
	_create_chains<Container, Chain>(container, pair_group_size, main, pend);

	std::size_t processed_pend_elements = _optimized_insertion<Container, Chain>(main, pend);

	_insert_remaining<Container, Chain>(container.size(), pair_group_size, main, pend, processed_pend_elements);

	_update_container<Container, Chain>(container, main, pair_group_size);
}

template <typename Container, typename Chain>
void PmergeMe::_merge_phase(Container& container, int pair_group_size) {
	typedef typename Container::iterator Iterator;

	int group_count = container.size() / pair_group_size;
	if (group_count < 2) {
		return;
	}

	int pair_count = group_count / 2;

	Iterator first_pair_begin = container.begin();
	Iterator last_pair_end = get_iterator_at_offset(container.begin(), pair_group_size * 2 * pair_count);

	int jump = 2 * pair_group_size;
	for (Iterator it = first_pair_begin; it != last_pair_end; std::advance(it, jump)) {
		Iterator this_group_largest_element = get_iterator_at_offset(it, pair_group_size - 1);
		Iterator next_group_largest_element = get_iterator_at_offset(it, pair_group_size * 2 - 1);

		if (_comp(next_group_largest_element, this_group_largest_element)) {
			_swap_with_next_pair(this_group_largest_element, pair_group_size);
		}
	}
	
	_merge_insertion_sort<Container, Chain>(container, pair_group_size * 2);
}

template <typename Container, typename Chain>
void PmergeMe::_create_chains(Container& container, int pair_group_size, Chain& main, Chain& pend) {
	typedef typename Container::iterator Iterator;

	int group_count = container.size() / pair_group_size;

	for (int i = 0; i < group_count; i++) {
		int largest_element_offset = (pair_group_size * i) + pair_group_size - 1;
		Iterator current = get_iterator_at_offset(container.begin(), largest_element_offset);
		
		if (i == 0 || i % 2 == 1) {
			main.push_back(current);
		} else {
			pend.push_back(current);
		}
	}
}

template <typename Container, typename Chain>
std::size_t PmergeMe::_optimized_insertion(Chain& main, Chain& pend) {
	typedef typename Container::iterator Iterator;
	typedef typename Chain::iterator ChainIterator;

	std::size_t processed_pend_elements = 0;
	for (std::size_t jacob_index = 2 ; processed_pend_elements < pend.size() ; jacob_index++) {
		std::size_t curr_jacobsthal = _jacobsthal_number(jacob_index);
		std::size_t group_size = _jacobsthal_number(jacob_index) - _jacobsthal_number(jacob_index - 1);
		if (group_size > pend.size() - processed_pend_elements) {
			break;
		}
		
		std::size_t elements_to_insert = group_size;
		int bound_adjustment = 0;

		ChainIterator pend_it = get_iterator_at_offset(pend.begin() + processed_pend_elements, (elements_to_insert - 1));
		while (elements_to_insert--) {
			ChainIterator search_bound = get_iterator_at_offset(main.begin(), _jacobsthal_number(jacob_index) + processed_pend_elements - bound_adjustment);

			ChainIterator insertion_point = std::upper_bound(main.begin(), search_bound, *pend_it, _comp<Iterator>);
			ChainIterator inserted = main.insert(insertion_point, *pend_it);

			if (std::distance(main.begin(), inserted) == static_cast<std::ptrdiff_t>(curr_jacobsthal + processed_pend_elements)) {
				bound_adjustment++;
			}
			
			std::advance(pend_it, -1);
		}
		processed_pend_elements += group_size;
	}
	return (processed_pend_elements);
}

template <typename Container, typename Chain>
void PmergeMe::_insert_remaining(std::size_t container_size, int pair_group_size, Chain& main, Chain& pend, std::size_t processed_pend_elements) {
	typedef typename Container::iterator Iterator;
	typedef typename Chain::iterator ChainIterator;

	int group_count = container_size / pair_group_size;

	bool is_odd = group_count % 2 == 1;
	for (size_t index = processed_pend_elements; index < pend.size(); index++) {
		ChainIterator current = get_iterator_at_offset(pend.begin(), index);
		ChainIterator bound = get_iterator_at_offset(main.begin(), main.size() - pend.size() + index + is_odd);

		ChainIterator insertion_point = std::upper_bound(main.begin(), bound, *current, _comp<Iterator>);
		main.insert(insertion_point, *current);
	}
}

template <typename Container, typename Chain>
void PmergeMe::_update_container(Container& container, Chain& main, int pair_group_size) {
	typedef typename Container::iterator Iterator;
	typedef typename Chain::iterator ChainIterator;

	Container sorted;
	for (ChainIterator it = main.begin(); it != main.end(); it++) {
		for (int group_pos = 0; group_pos < pair_group_size; group_pos++) {
			Iterator group_anchor = *it;
			std::advance(group_anchor, -pair_group_size + group_pos + 1);
			sorted.push_back(*group_anchor);
		}
	}

	std::copy(sorted.begin(), sorted.end(), container.begin());
}

/**
 * Swaps a group of elements with the next adjacent group of equal size.
 * The iterator points to the largest element of the first group.
 * 
 * @param rightmost_element_it Iterator pointing to the largest element of the first group
 * @param pair_group_size Size of each group to be swapped
 */
template <typename Iterator>
void _swap_with_next_pair(Iterator rightmost_element_it, int pair_group_size) {
	Iterator current_pair_begin = get_iterator_at_offset(rightmost_element_it, -pair_group_size + 1);
	Iterator next_pair_begin = get_iterator_at_offset(current_pair_begin, pair_group_size);
	
	while (current_pair_begin != next_pair_begin) {
		std::iter_swap(current_pair_begin, get_iterator_at_offset(current_pair_begin, pair_group_size));
		current_pair_begin++;
	}
}

template <typename Iterator>
bool _comp(Iterator lv, Iterator rv) {
	PmergeMe::comparison_counter++;
	return *lv < *rv;
}

template <typename Iterator> 
Iterator get_iterator_at_offset(Iterator it, int steps) {
	std::advance(it, steps);
	return it;
}

template <typename Container>
void print_container(Container& container) {
	for (typename Container::iterator it = container.begin(); it != container.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

#endif