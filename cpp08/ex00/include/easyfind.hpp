#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iostream>
# include <vector>
# include <list>
# include <deque>
# include <exception>

template<typename T>
int easyfind(T& container, int value) throw(std::runtime_error) {
	typename T::iterator it = std::find(container.begin(), container.end(), value);

	if (it == container.end()) {
		throw std::runtime_error("Error: Value not found inside container");
	}

	return std::distance(container.begin(), it);
}

template<typename T>
void testEasyFind(T& container, int value) {
	try {
		int index = easyfind(container, value);
		std::cout << "Found at index: " << index << "\n";
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

#endif