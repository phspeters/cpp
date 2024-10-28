#include "Harl.hpp"

int main() {
	std::cout << "Constructor:\n";
	Harl harl;

	std::cout << "\nDEBUG LEVEL:\n";
	harl.complain("DEBUG");

	std::cout << "\nINFO LEVEL:\n";
	harl.complain("INFO");

	std::cout << "\nWARNING LEVEL:\n";
	harl.complain("WARNING");

	std::cout << "\nERROR LEVEL:\n";
	harl.complain("ERROR");

	std::cout << "\nINVALID LEVEL:\n";
	harl.complain("INVALID");

	std::cout << "\nDestructor:\n";
	return 0;
}
