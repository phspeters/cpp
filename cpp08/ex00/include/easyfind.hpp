#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <stdexcept>

template <typename T>
int easyfind(const T& container, int value) {
    typename T::const_iterator it =
        std::find(container.begin(), container.end(), value);

    if (it == container.end()) {
        throw std::runtime_error("Error: Value not found inside container");
    }

    return std::distance(container.begin(), it);
}

template <typename T>
void testEasyFind(const T& container, int value) {
    try {
        int index = easyfind(container, value);
        std::cout << "Found at index: " << index << "\n";
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

#endif