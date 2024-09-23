#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl harl;
	
	if (argc == 2)
	{
		harl.complain(argv[1]);
		return (0);
	}
	
	std::cerr << "Usage: ./harlFilter [DEBUG|INFO|WARNING|ERROR]\n";
	return (1);
}
