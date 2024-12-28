#include "easyfind.hpp"

int main() {
	int arr[] = {1, 2, 3, 4, 5};
	const size_t arr_size = sizeof(arr) / sizeof(arr[0]);
	
	std::vector<int> vec(arr, arr + arr_size);
	std::list<int> lst(arr, arr + arr_size);
	std::deque<int> deq(arr, arr + arr_size);
	
	std::cout << "All containers have been initialized with { 1, 2, 3, 4, 5 }\n";

	std::cout << "\nTESTING VECTOR\n";
	std::cout << "Searching for 3\n";
	testEasyFind(vec, 3);
	std::cout << "Searching for 6\n";
	testEasyFind(vec, 6);

	std::cout << "\nTESTING LIST\n";
	std::cout << "Searching for 3\n";
	testEasyFind(lst, 3);
	std::cout << "Searching for 6\n";
	testEasyFind(lst, 6);

	std::cout << "\nTESTING DEQUE\n";
	std::cout << "Searching for 3\n";
	testEasyFind(deq, 3);
	std::cout << "Searching for 6\n";
	testEasyFind(deq, 6);

	return (0);
}
