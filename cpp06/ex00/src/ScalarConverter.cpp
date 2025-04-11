#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &obj) { *this = obj; }

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj) {
    (void)obj;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(std::string input) {
    double literal = 0;
    bool isConvertable = true;

    if (isChar(input)) {
        std::cout << "Value is a --> char <--\n";
        literal = input[0];
    } else if (isInt(input)) {
        std::cout << "Value is an --> int <--\n";
        literal = std::atoi(input.c_str());
    } else if (isFloat(input)) {
        std::cout << "Value is a --> float <--\n";
        literal = std::atof(input.c_str());
    } else if (isDouble(input)) {
        std::cout << "Value is a --> double <--\n";
        literal = std::strtod(input.c_str(), NULL);
    } else {
        isConvertable = false;
        std::cout << "Error: Unknown value type\n";
    }

    if (isConvertable) {
        safeCastChar(literal);
        safeCastInt(literal);
        safeCastFloat(literal);
        safeCastDouble(literal);
    }
}
