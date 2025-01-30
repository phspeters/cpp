#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Usage: ./btc [filename]" << std::endl;
		return 1;
	}

	BitcoinExchange exchange;
	
	exchange.displayConvertions("data/data.csv", argv[1]);

	return 0;
}
