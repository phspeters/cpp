#ifndef CONVERTTYPES_HPP
#define CONVERTTYPES_HPP

#include <iostream>
#include <sstream>
#include <climits>
#include <cfloat>
#include <cstdlib>
#include <cmath>

void	convertChar(std::string input);
void	convertInt(std::string input);
void	convertFloat(std::string input);
void	convertDouble(std::string input);
void	convertPseudo(std::string input);

void	safeCastChar(double input);
void	safeCastInt(double input);
void	safeCastFloat(double input);
void	safeCastDouble(double input);

#endif