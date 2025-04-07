#include "RPN.hpp"

/*
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
> 42
./RPN "7 7 * 7 -"
> 42
./RPN "1 2 * 2 / 2 * 2 4 - +"
> 0
./RPN "(1 + 1)"
> Error
*/
int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Usage: ./RPN [reverse Polish notation expression]" << std::endl;
		return 1;
	}

	RPN rpn;

	rpn.solveExpression(argv[1]);
	
	return 0;
}
