#include "ConvertTypes.hpp"

void	convertChar(std::string input)
{
	char c = input[0];

	std::cout << "char: '" << c << "'\n";

	safeCastInt(c);
	safeCastFloat(c);
	safeCastDouble(c);
}

void	convertInt(std::string input)
{
	std::istringstream iss(input);
	int i;
	iss >> i;

	safeCastChar(i);

	std::cout << "int: '" << i << "'\n";

	safeCastFloat(i);
	safeCastDouble(i);
}

void	convertFloat(std::string input)
{
	std::istringstream iss(input);
	float f;
	iss >> f;

	safeCastChar(f);
	safeCastInt(f);

	if (f - static_cast<int>(f) == 0)
		std::cout << "float: '" << f << ".0f'\n";
	else
		std::cout << "float: '" << f << "f'\n";

	safeCastDouble(f);
}

void	convertDouble(std::string input)
{
	double d = strtod(input.c_str(), NULL);

	safeCastChar(d);
	safeCastInt(d);
	safeCastFloat(d);
	
	if (d - static_cast<int>(d) == 0)
		std::cout << "double: '" << d << ".0'\n";
	else
		std::cout << "double: '" << d << "'\n";
}

void	convertPseudo(std::string input)
{
	std::cout << "char: impossible\n";

	std::cout << "int: impossible\n";

	double d = strtod(input.c_str());
	if (d == INFINITY || d == -INFINITY || d != d)
		std::cout << "float: " << d << "f\n";
	else
		std::cout << "float: impossible\n";
}

void	safeCastChar(double input)
{
	if (input > 127 || input < -128)
		std::cout << "char: impossible\n";
	else if (std::isprint(static_cast<char>(input)))
		std::cout << "char: '" << static_cast<char>(input) << "'\n";
	else
		std::cout << "char: non displayable\n";
}

void	safeCastInt(double input)
{
	if (input > INT_MAX || input < INT_MIN)
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(input) << "\n";
}

void	safeCastFloat(double input)
{
	if (input > FLT_MAX || input < -FLT_MAX)
		std::cout << "float: impossible\n";
	else if (input - static_cast<int>(input) == 0)
		std::cout << "float: " << static_cast<float>(input) << ".0f\n";
	else
		std::cout << "float: " << static_cast<float>(input) << "f\n";
}

void	safeCastDouble(double input)
{
	if (input > DBL_MAX || input < -DBL_MAX)
		std::cout << "double: impossible\n";
	else if (input - static_cast<int>(input) == 0)
		std::cout << "double: " << static_cast<double>(input) << ".0\n";
	else
		std::cout << "double: " << static_cast<double>(input) << "\n";
}
