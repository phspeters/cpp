#include "easyfind.hpp"

template<typename T>
int easyfind(T& container, int value) {

	typename T::iterator it = std::find(container.begin(), container.end(), value);

	if (it == container.end()) {
		throw std::runtime_error("Value not found in container");
	}

	return std::distance(container.begin(), it);
}

template<typename T>
void	testEasyFind(T& container, int value)
{
	try
	{
		int index = easyfind(container, value);
		std::cout << "Found at index: " << index << "\n";
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}