#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

# include <cstdlib>
# include <fstream>
# include <iostream>
# include <map>
# include <sstream>
# include <string>
# include <sys/stat.h>

class BitcoinExchange {
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange & src);
	~BitcoinExchange();
	BitcoinExchange & operator=(const BitcoinExchange & rhs);

	void displayConvertions(std::string btc_database, std::string query_database);

private:
	std::map<std::string, double> _data;
	std::map<std::string, double> _query;

	const char* _validateFile(const std::string & filename);
	void _loadCsv(const std::string & filename);
	void _convertQueries(const std::string & filename);
	void _convertValue(const std::pair<std::string, double> & entry);

	bool _isValidDate(const std::string & date);
	bool _isValidRecord(const std::string & date);
	bool _isValidValue(double & value);
	std::string _trim(const std::string & str);
};

#endif