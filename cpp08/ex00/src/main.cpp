#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

int main() {
	int arr[] = {1, 2, 3, 4, 5};
	const size_t arr_size = sizeof(arr) / sizeof(arr[0]);
	
	std::vector<int> vec(arr, arr + arr_size);
	std::list<int> lst(arr, arr + arr_size);
	std::deque<int> deq(arr, arr + arr_size);
	
	std::cout << "All containers have been initialized with { 1, 2, 3, 4, 5 }\n";

	std::cout << "\nTESTING VECTOR\n";
	std::cout << "Searching for number 3\n";
	testEasyFind(vec, 3);
	std::cout << "Searching for number 6\n";
	testEasyFind(vec, 6);

	std::cout << "\nTESTING LIST\n";
	std::cout << "Searching for number 2\n";
	testEasyFind(lst, 2);
	std::cout << "Searching for number 10\n";
	testEasyFind(lst, 10);

	std::cout << "\nTESTING DEQUE\n";
	std::cout << "Searching for number 4\n";
	testEasyFind(deq, 4);
	std::cout << "Searching for number 42\n";
	testEasyFind(deq, 42);

	return (0);
}
