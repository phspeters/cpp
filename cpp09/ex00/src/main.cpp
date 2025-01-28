#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Usage: ./btc [filename]" << std::endl;
		return 1;
	}

	BitcoinExchange exchange;
	exchange.loadCsv("data/data.csv");
	exchange.loadQuery(argv[1]);
	exchange.displayConvertion();
	return 0;
}
