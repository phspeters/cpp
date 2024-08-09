#include <iostream>

int	main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "The value of the string variable: " << str << std::endl;
	std::cout << "The memory address of the string variable: " << &str << std::endl;
	std::cout << std::endl;

	std::cout << "The value of the stringPTR value: " << stringPTR << std::endl;
	std::cout << "The memory address of the stringPTR variable: " << &stringPTR << std::endl;
	std::cout << std::endl;

	std::cout << "The value of the stringREF variable " << stringREF << std::endl;
	std::cout << "The memory address of the stringREF variable: " << &stringREF << std::endl;
	std::cout << std::endl;
}