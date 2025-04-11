#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <sys/stat.h>

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

class BitcoinExchange {
   public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& src);
    ~BitcoinExchange();
    BitcoinExchange& operator=(const BitcoinExchange& rhs);

    int displayConvertions(std::string btc_database,
                           std::string query_database);

   private:
    std::map<std::string, double> _data;
    std::map<std::string, double> _query;

    int _loadCsv(const std::string& filename);
    int _convertQueries(const std::string& filename);
    void _convertValue(const std::pair<std::string, double>& entry);

    bool _isValidFile(const std::string& filename);
    bool _isValidHeader(const std::string& header);
    bool _isValidDate(const std::string& date);
    bool _isValidRecord(const std::string& date);
    bool _isValidValue(double& value);
    std::string _trim(const std::string& str);
};

#endif