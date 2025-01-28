#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src) {
	if (this != &src)
		*this = src;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & rhs) {
	if (this != &rhs) {
		this->_data = rhs._data;
		this->_query = rhs._query;
	}
	return *this;
}
