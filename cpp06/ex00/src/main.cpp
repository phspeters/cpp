#include "ScalarConverter.hpp"

int main()
{
	std::string input;

	std::cout << "Enter a value: ";
	std::cin >> input;
	ScalarConverter::convert(input);
	return (0);
}