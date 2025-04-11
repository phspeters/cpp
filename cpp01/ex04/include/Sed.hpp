#ifndef SED_HPP
#define SED_HPP

#include <sys/stat.h>

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

class sed {
   public:
    sed(std::string filename, std::string toSearch, std::string toReplace);
    ~sed();

    void replace();

   private:
    std::string _filename;
    std::string _toReplace;
    std::string _toSearch;
    std::ifstream _file;
};

#endif