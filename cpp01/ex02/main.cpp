#include <iostream>

int	main()
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "The value of the string variable: " << string << std::endl;
	std::cout << "The memory address of the string variable: " << &string << std::endl;
	std::cout << std::endl;

	std::cout << "The value of the stringPTR value: " << stringPTR << std::endl;
	std::cout << "The memory address of the stringPTR variable: " << &stringPTR << std::endl;
	std::cout << std::endl;

	std::cout << "The value of the stringREF variable " << stringREF << std::endl;
	std::cout << "The memory address of the stringREF variable: " << &stringREF << std::endl;
	std::cout << std::endl;
}