#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange & src) {
	if (this != &src) {
		*this = src;
	}
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange & rhs) {
	if (this != &rhs) {
		this->_data = rhs._data;
	}
	return *this;
}

void BitcoinExchange::displayConvertions(std::string btc_database, std::string query_database) {
	this->_loadCsv(btc_database);
	this->_convertQueries(query_database);
}

void BitcoinExchange::_loadCsv(const std::string & filename) {
	std::ifstream file(_validateFile(filename));

	std::string line;
	getline(file, line);

	while (getline(file, line)) {
		size_t comma = line.find(',');
		std::string key = line.substr(0, comma);
		double value = std::strtod(line.substr(comma + 1).c_str(), NULL);
		this->_data[key] = value;
	}
}

void BitcoinExchange::_convertQueries(const std::string & filename) {
	std::ifstream file(_validateFile(filename));

	std::string line;
	getline(file, line);
	if (!_isValidHeader(line)) {
		std::cout << "Error: invalid header => '" << line << "'\n";
		return;
	}

	while (getline(file, line)) {
		size_t pipe = line.find('|');
		if (pipe == std::string::npos) {
			std::cout << "Error: invalid input => missing divider '|'\n";
			continue;
		}

		std::string date = _trim(line.substr(0, pipe));
		if (!_isValidDate(date)) {
			std::cout << "Error: invalid date => '" << date << "'\n";
			continue;
		}
		
		if (!_isValidRecord(date)) {
			std::cout << "Error: records start at 2009-01-02 and end at 2022-03-29\n";
			continue;
		}

		std::string value_str = _trim(line.substr(pipe + 1));
		if (value_str.empty()) {
			std::cout << "Error: invalid value => ''\n";
			continue;
		}

		char *end;
		double value = std::strtod(value_str.c_str(), &end);
		if (!_isValidValue(value) || *end != '\0') {
			std::cout << "Error: invalid value => '" << value_str << "'" << (value > 1000 ? ": Too large a number\n" : "\n");
			continue;
		}

		std::pair<std::string, double> query = std::make_pair(date, value);
		_convertValue(query);
	}
}


void BitcoinExchange::_convertValue(const std::pair<std::string, double> & entry) {
	std::map<std::string, double>::iterator data_it = _data.lower_bound(entry.first);
			
	if (data_it->first != entry.first) {
		--data_it;
	}
	
	double result = entry.second * data_it->second;
	std::cout << entry.first << " => " << entry.second << " = " << result << std::endl;
}

const char* BitcoinExchange::_validateFile(const std::string & filename) {
	if (filename.size() < 4 || (filename.substr(filename.size() - 4) != ".txt" && filename.substr(filename.size() - 4) != ".csv")) {
		std::cerr << "Error: file '" << filename << "' does not have a .txt or .csv extension" << std::endl;
		exit(1);
	}
	
	struct stat pathStat;
	if (stat(filename.c_str(), &pathStat) != 0) {
		std::cerr << "Error: file '" << filename << "' does not exist" << std::endl;
		exit(1);
	}
	
	if (!S_ISREG(pathStat.st_mode)) {
		std::cerr << "Error: '" << filename << "' is not a regular file" << std::endl;
		exit(1);
	}

	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		std::cerr << "Error: could not open file '" << filename << "'" << std::endl;
		exit(1);
	}

	if (file.peek() == std::ifstream::traits_type::eof()) {
		std::cerr << "Error: file '" << filename << "' is empty" << std::endl;
		exit(1);
	}

	return filename.c_str();
}

bool BitcoinExchange::_isValidHeader(const std::string & header) {
	std::istringstream ss(header);
	std::string date, pipe, value;

	ss >> date >> pipe >> value;
	if (ss.fail() || pipe != "|" || date != "date" || value != "value") {
		return false;
	}

	return true;
}

bool BitcoinExchange::_isValidDate(const std::string& date) {
	std::istringstream ss(date);
	int year, month, day;
	char sep1, sep2;

	ss >> year >> sep1 >> month >> sep2 >> day;

	if (ss.fail() || sep1 != '-' || sep2 != '-' || day < 1 || month < 1 || month > 12 || year < 0) {
		return false;
	}

	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
		daysInMonth[1] = 29;
	}

	return day <= daysInMonth[month - 1];
}

bool BitcoinExchange::_isValidRecord(const std::string & date) {
	std::istringstream ss(date);
	int year;

	ss >> year;

	if (year < 2009 || year > 2022) {
		return false;
	}

	if (date < "2009-01-02" || date > "2022-03-29") {
		return false;
	}

	return true;
}

bool BitcoinExchange::_isValidValue(double & value) {
	if (value < 0 || value > 1000) {
		return false;
	}

	return true;


}

std::string BitcoinExchange::_trim(const std::string &s) {
	size_t start = s.find_first_not_of(" \t\n\r\f\v");
	if (start == std::string::npos){
		return "";
	}
	
	size_t end = s.find_last_not_of(" \t\n\r\f\v");
	return s.substr(start, end - start + 1);
}
