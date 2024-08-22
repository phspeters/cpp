#include "Harl.hpp"

int main()
{
	Harl harl;
	
	std::cout << std::endl;
	std::cout << "Harl started to complain:\n" << std::endl;

	std::cout << "DEBUG LEVEL:" << std::endl;
	harl.complain("DEBUG");
	std::cout << std::endl;

	std::cout << "INFO LEVEL:" << std::endl;
	harl.complain("INFO");
	std::cout << std::endl;

	std::cout << "WARNING LEVEL:" << std::endl;
	harl.complain("WARNING");
	std::cout << std::endl;

	std::cout << "ERROR LEVEL:" << std::endl;
	harl.complain("ERROR");
	std::cout << std::endl;

	std::cout << "INVALID LEVEL:" << std::endl;
	harl.complain("INVALID");
	std::cout << std::endl;

	return 0;
}