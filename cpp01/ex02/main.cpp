#include <iostream>

int	main()
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "The value of the string variable: " << string << '\n';
	std::cout << "The memory address of the string variable: " << &string << '\n';
	std::cout << '\n';

	std::cout << "The value of the stringPTR value: " << stringPTR << '\n';
	std::cout << "The memory address of the stringPTR variable: " << &stringPTR << '\n';
	std::cout << '\n';

	std::cout << "The value of the stringREF variable " << stringREF << '\n';
	std::cout << "The memory address of the stringREF variable: " << &stringREF << '\n';
	std::cout << '\n';
}