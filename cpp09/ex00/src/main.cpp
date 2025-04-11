#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./btc [filename]" << std::endl;
        return 1;
    }

    BitcoinExchange exchange;

    return exchange.displayConvertions("data/data.csv", argv[1]);
}
