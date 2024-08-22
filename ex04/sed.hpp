#ifndef SED_HPP
#define SED_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

class sed
{
private:
	std::string _filename;
	std::string _toReplace;
	std::string _toSearch;
	std::ifstream _file;

public:
	sed(std::string filename, std::string toSearch, std::string toReplace);
	~sed();
	void replace();
};

#endif