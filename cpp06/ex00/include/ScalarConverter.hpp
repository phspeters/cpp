#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include "DefineTypes.hpp"
#include "ConvertTypes.hpp"

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &obj);
	ScalarConverter &operator=(const ScalarConverter &obj);

public:
	~ScalarConverter();

	static void convert(std::string input);
};

#endif