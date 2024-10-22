#include "DefineTypes.hpp"

bool	isChar(std::string str)
{
	return (str.length() == 1 && isprint(str[0]) && !isdigit(str[0]));
}

bool	isInt(std::string str)
{
	std::istringstream iss(str);
	int i;

	iss >> i;
	if (iss.fail() || !iss.eof())
		return (false);
		
	return (true);
}

bool	isFloat(std::string str)
{
	std::istringstream iss(str);
	float f;

	iss >> f;
	if (iss.fail() || iss.eof())
		return (false);

	std::string suffix;
	iss >> suffix;
	if (suffix != "f" && !iss.eof())
		return (false);
	
	return (true);
}

bool	isDouble(std::string str)
{
	std::istringstream iss(str);
	double d;

	iss >> d;
	if (iss.fail() || !iss.eof())
		return (false);
	
	return (true);
}

bool	isPseudo(std::string str)
{
	return (str == "nan" || str == "+inf" || str == "-inf"
		|| str == "+inff" || str == "-inff");
}
