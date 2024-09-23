#include "Harl.hpp"

int main()
{
	Harl harl;
	
	std::cout << '\n';
	std::cout << "Harl started to complain:\n\n";

	std::cout << "DEBUG LEVEL:\n";
	harl.complain("DEBUG");
	std::cout << '\n';

	std::cout << "INFO LEVEL:\n";
	harl.complain("INFO");
	std::cout << '\n';

	std::cout << "WARNING LEVEL:\n";
	harl.complain("WARNING");
	std::cout << '\n';

	std::cout << "ERROR LEVEL:\n";
	harl.complain("ERROR");
	std::cout << '\n';

	std::cout << "INVALID LEVEL:\n";
	harl.complain("INVALID");
	std::cout << '\n';

	return 0;
}
