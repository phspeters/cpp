#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	if (argc == 1) {
		std::cerr << "Usage: ./PmergeMe [sequence] [to] [merge]..." << std::endl;
		return 1;
	}
	PmergeMe pm;
	std::vector<int> vec;
	for (int i = 1; i < argc; i++) {
		vec.push_back(std::atoi(argv[i]));
	}

	pm.sort_vec(vec);
}
