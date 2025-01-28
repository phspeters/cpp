#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>

class BitcoinExchange {
public:
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange const & src);
	~BitcoinExchange();
	BitcoinExchange & operator=(BitcoinExchange const & rhs);

	void loadCsv(std::string const & filename);
	void loadQuery(std::string const & filename);
	void displayConvertion();

private:
	std::map<std::string, double> _data;
	std::map<std::string, double> _query;
};

#endif