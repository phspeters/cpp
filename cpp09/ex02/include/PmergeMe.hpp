#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <cmath>
# include <algorithm>
# include <deque>
# include <vector>

class PmergeMe
{
  public:
    PmergeMe();
    PmergeMe(const PmergeMe& pm);
    PmergeMe& operator=(const PmergeMe& pm);
    ~PmergeMe();

    void sort_vec(std::vector<int>& vec);
    void sort_deque(std::deque<int>& deque);

	size_t get_jacobsthal_cache(size_t n);

	static int nbr_of_comps;

  private:
	size_t _jacobsthal_number(size_t n);
	static size_t _jacobsthal_cache[62];

    template <typename Container> void _merge_insertion_sort(Container& container, int pair_group_size);
    template <typename Iterator> void _swap_with_next_pair(Iterator rightmost_element_it, int pair_group_size);
};

size_t PmergeMe::get_jacobsthal_cache(size_t n) {
	return _jacobsthal_cache[n];
}

size_t PmergeMe::_jacobsthal_number(size_t n) {
	size_t cache = get_jacobsthal_cache(n);
	if(cache)
		return cache;

	size_t result = round((pow(2, n + 1) + pow(-1, n)) / 3);
	_jacobsthal_cache[n] = result;
	return result;
}

template <typename Container>
void _print_container(Container& container) {
	for (typename Container::iterator it = container.begin(); it != container.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

template <typename Container, typename Iterator>
void insert_pair_at_position(Container& container, Iterator position, Iterator group_start, int pair_group_size) {
    container.insert(position, group_start, group_start + pair_group_size);
}

template <typename Iterator>
bool _comp(Iterator lv, Iterator rv) {
	PmergeMe::nbr_of_comps++;
	return *lv < *rv;
}

template <typename Iterator> 
Iterator get_iterator_at_offset(Iterator it, int steps) {
    std::advance(it, steps);
    return it;
}

/**
 * Swaps a group of elements with the next adjacent group of equal size.
 * The iterator points to the largest element of the first group.
 * 
 * @param rightmost_element_it Iterator pointing to the largest element of the first group
 * @param pair_group_size Size of each group to be swapped
 */
template <typename Iterator>
void PmergeMe::_swap_with_next_pair(Iterator rightmost_element_it, int pair_group_size) {
    Iterator current_pair_begin = get_iterator_at_offset(rightmost_element_it, -pair_group_size + 1);
    Iterator next_pair_begin = get_iterator_at_offset(current_pair_begin, pair_group_size);
    
    while (current_pair_begin != next_pair_begin) {
        std::iter_swap(current_pair_begin, get_iterator_at_offset(current_pair_begin, pair_group_size));
        current_pair_begin++;
    }
}

template <typename Container, typename Iterator>
void insert_pair_in_chain(Container& main, Iterator pair_begin, int pair_group_size) {
	Iterator current = pair_begin;
	for (int i = 0; i < pair_group_size; i++) {
		main.push_back(*current);
		current++;
	}
}


template <typename Container>
void PmergeMe::_merge_insertion_sort(Container& container, int pair_group_size) {
    typedef typename Container::iterator Iterator;

    int group_count = container.size() / pair_group_size;
    if (group_count < 2) {
        return;
	}

	int pair_count = group_count / 2;
    //bool is_odd = group_count % 2 == 1;

	//std::cout << "Pair group size: " << pair_group_size << std::endl;
	//std::cout << "original: ";
	//_print_container(container);

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

	//std::cout << "swapped: ";
	//_print_container(container);

    _merge_insertion_sort(container, pair_group_size * 2);

/*---------------------------------------------------------------------------*/

    Container main;
    Container pend;

	/* Insert elements into main and pend chains */
	for (int i = 0; i < group_count; i++) {
		Iterator current = get_iterator_at_offset(container.begin(), pair_group_size * i);
		
		if (i == 0 || i % 2 == 1) {
			// For i=0 (b1) and all odd indices (a1, a2, a3...) -> insert to main
			insert_pair_in_chain(main, current, pair_group_size);
		} else {
			// For all other even indices (b2, b3, b4...) -> insert to pend
			insert_pair_in_chain(pend, current, pair_group_size);
		}
	}

	//std::cout << "main: ";
	//_print_container(main);
	//std::cout << "pend: ";
	//_print_container(pend);

//TODO insertion
}

#endif