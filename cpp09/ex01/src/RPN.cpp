#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(RPN const& src) {
    if (this != &src) {
        *this = src;
    }
}

RPN::~RPN() {}

RPN& RPN::operator=(RPN const& rhs) {
    if (this != &rhs) {
        _stack = rhs._stack;
    }

    return *this;
}

int RPN::solveExpression(std::string expression) {
    if (!_isValidExpression(expression)) {
        return 1;
    }

    std::string token;
    std::istringstream iss(expression);

    while (iss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (_stack.size() < 2) {
                std::cout << "Error: not enough operands to perform operation '"
                          << token << "'" << std::endl;
                return 1;
            }

            int a = _stack.top();
            _stack.pop();

            int b = _stack.top();
            _stack.pop();

            if (token == "/" && a == 0) {
                std::cout << "Error: division by zero" << std::endl;
                return 1;
            }

            if (token == "+") {
                _stack.push(b + a);
            } else if (token == "-") {
                _stack.push(b - a);
            } else if (token == "*") {
                _stack.push(b * a);
            } else if (token == "/") {
                _stack.push(b / a);
            }

        } else {
            _stack.push(atoi(token.c_str()));
        }
    }

    std::cout << _stack.top() << std::endl;

    return 0;
}

bool RPN::_isValidExpression(std::string expression) {
    std::string token;
    std::istringstream iss(expression);

    int operands = 0;
    int operators = 0;

    while (iss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            operators++;
        } else if (_isValidOperand(token)) {
            operands++;
        } else {
            std::cout << "Error: invalid token \'" << token << "\'"
                      << std::endl;
            return false;
        }
    }

    if (operands > operators + 1) {
        std::cout << "Error: RPN expression is malformed - too many operands ("
                  << operands << " operands, " << operators << " operators)"
                  << std::endl
                  << "In valid RPN notation, with n operands you need exactly "
                     "(n-1) operators"
                  << std::endl
                  << "Please either add " << operands - (operators + 1)
                  << " more operators or remove " << operands - (operators + 1)
                  << " operands" << std::endl;
        return false;
    } else if (operands < operators + 1) {
        std::cout << "Error: RPN expression is malformed - too many operators ("
                  << operators << " operators, " << operands << " operands)"
                  << std::endl
                  << "In valid RPN notation, with n operands you need exactly "
                     "(n-1) operators"
                  << std::endl
                  << "Please either add " << (operators + 1) - operands
                  << " more operands or remove " << (operators + 1) - operands
                  << " operators" << std::endl;
        return false;
    }

    return true;
}

bool RPN::_isValidOperand(std::string token) {
    if (token.size() == 1 && token[0] >= '0' && token[0] <= '9') {
        return true;
    }

    return false;
}
