#include "RPN.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./RPN [reverse Polish notation expression]"
                  << std::endl;
        return 1;
    }

    RPN rpn;

    return rpn.solveExpression(argv[1]);
}
