#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &obj)
{
	*this = obj;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj)
{
	(void)obj;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::convert(std::string input)
{
	if (isChar(input))
		convertChar(input);
	else if (isInt(input))
		convertInt(input);
	else if (isFloat(input))
		convertFloat(input);
	else if (isDouble(input))
		convertDouble(input);
	else if (isPseudo(input))
		convertPseudo(input);
	else
		std::cout << "Unknown type\n";
}
