#include "PmergeMe.hpp"
#include <limits.h>
#include <ctime>
#include <iomanip>
#define DEBUG_MODE 0

int max_comparison(int n)
{
	int sum = 0;
	for (int k = 1; k <= n; ++k) {
		double value = (3.0 / 4.0) * k;
		sum += static_cast<int>(ceil(log2(value)));
	}
	return sum;
}

int main(int argc, char **argv) {
	if (argc == 1) {
		std::cerr << "Usage: ./PmergeMe [sequence] [to] [merge]..." << std::endl;
		return 1;
	}

	std::vector<int> vec;
	vec.reserve(argc - 1);

	for (int i = 1; i < argc; i++) {
		char* endptr;
		long value = std::strtol(argv[i], &endptr, 10);
		
		if (*endptr != '\0' || endptr == argv[i]) {
			std::cerr << "Error: '" << argv[i] << "' is not a valid integer." << std::endl;
			return 1;
		}

		if (value > INT_MAX || value < 0) {
			std::cerr << "Error: '" << argv[i] << "' is out of positive integer range." << std::endl;
			return 1;
		}
		
		vec.push_back(static_cast<int>(value));
	}
	
	// Create deque with vector's data
	std::deque<int> deq(vec.begin(), vec.end());
	
	PmergeMe pm;

	std::cout << "Before: ";
	print_container(vec);

	clock_t start_vec = clock();
	pm.sort_vec(vec);
	clock_t end_vec = clock();
	double vec_time = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC * 1000000.0;

	clock_t start_deq = clock();
	pm.sort_deque(deq);
	clock_t end_deq = clock();
	double deq_time = static_cast<double>(end_deq - start_deq) / CLOCKS_PER_SEC * 1000000.0;

	std::cout << "After:  ";
	print_container(vec);
	//std::cout << std::fixed << std::setprecision(6);
	std::cout << "Time to process a range of 5 elements with std::vector : " << vec_time << " us\n";
	std::cout << "Time to process a range of 5 elements with std::deque  : " << deq_time << " us\n";
	if (DEBUG_MODE) {
		std::cout << std::endl;
		std::cout << "Number of comparisons: " << PmergeMe::comparison_counter << std::endl;
		std::cout << "Maximum number of comparisons: " << max_comparison(argc - 1) << std::endl;
	}
}
