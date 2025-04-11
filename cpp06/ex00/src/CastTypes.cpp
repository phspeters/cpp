#include "CastTypes.hpp"

void safeCastChar(double input) {
    if (input > 127 || input < -128 || input != input) {
        std::cout << "char: impossible\n";
    } else if (std::isprint(static_cast<char>(input))) {
        std::cout << "char: " << static_cast<char>(input) << "\n";
    } else {
        std::cout << "char: non displayable\n";
    }
}

void safeCastInt(double input) {
    if (input > std::numeric_limits<int>::max() ||
        input < std::numeric_limits<int>::min() || input != input) {
        std::cout << "int: impossible\n";
    } else {
        std::cout << "int: " << static_cast<int>(input) << "\n";
    }
}

void safeCastFloat(double input) {
    if (std::isinf(input)) {
        std::cout << "float: " << (input > 0 ? "+inff" : "-inff") << "\n";
    } else if (input > std::numeric_limits<float>::max() ||
               input < -std::numeric_limits<float>::max()) {
        std::cout << "float: impossible\n";
    } else if (input - static_cast<int>(input) == 0) {
        std::cout << "float: " << static_cast<float>(input) << ".0f\n";
    } else {
        std::cout << "float: " << static_cast<float>(input) << "f\n";
    }
}

void safeCastDouble(double input) {
    if (std::isinf(input)) {
        std::cout << "double: " << (input > 0 ? "+inf" : "-inf") << "\n";
    } else if (input - static_cast<int>(input) == 0) {
        std::cout << "double: " << static_cast<double>(input) << ".0\n";
    } else {
        std::cout << "double: " << static_cast<double>(input) << "\n";
    }
}
