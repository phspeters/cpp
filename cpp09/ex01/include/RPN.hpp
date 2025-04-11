#ifndef RPN_HPP
#define RPN_HPP

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>

class RPN {
   public:
    RPN();
    RPN(RPN const& src);
    ~RPN();
    RPN& operator=(RPN const& rhs);

    int solveExpression(std::string expression);

   private:
    std::stack<int> _stack;

    bool _isValidExpression(std::string expression);
    bool _isValidOperand(std::string token);
};

#endif