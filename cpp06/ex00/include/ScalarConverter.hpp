#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include "CastTypes.hpp"
#include "DefineTypes.hpp"

class ScalarConverter {
   public:
    ~ScalarConverter();

    static void convert(std::string input);

   private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& obj);
    ScalarConverter& operator=(const ScalarConverter& obj);
};

#endif