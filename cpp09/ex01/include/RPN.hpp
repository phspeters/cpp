#ifndef RPN_HPP
# define RPN_HPP

# include <cstdlib>
# include <iostream>
# include <sstream>
# include <string>
# include <stack>

class RPN {
public:
	RPN();
	RPN(RPN const & src);
	~RPN();
	RPN & operator=(RPN const & rhs);

	void solveExpression(std::string expression);

private:
	std::stack<int> _stack;

	void _validateExpression(std::string expression);
	bool _isValidOperand(std::string token);
};

#endif