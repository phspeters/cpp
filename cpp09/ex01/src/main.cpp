#include "RPN.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Usage: ./rpn [inverted Polish mathematical expression]" << std::endl;
		return 1;
	}

	RPN rpn;

	rpn.solveExpression(argv[1]);
	
	return 0;
}
