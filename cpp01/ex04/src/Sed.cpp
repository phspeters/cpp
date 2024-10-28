#include "Sed.hpp"

sed::sed(std::string filename, std::string toSearch, std::string toReplace) {
	struct stat pathStat;
	if (stat(filename.c_str(), &pathStat) != 0) {
		std::cerr << "Error: file does not exist\n";
		exit(1);
	}

	// S_ISREG macro checks if it's a regular file
	if (!S_ISREG(pathStat.st_mode)) {
		std::cerr << "Error: path is not a regular file\n";
		exit(1);
	}

	_file.open(filename.c_str());
	if (!_file.is_open()) {
		std::cerr << "Error: could not open input file\n";
		exit(1);
	}

	_filename = filename;
	_toSearch = toSearch;
	_toReplace = toReplace;
}

sed::~sed() {
	_file.close();
}

void sed::replace() {
	std::ofstream output((_filename + ".replace").c_str());
	if (!output.is_open()) {
		std::cerr << "Error: could not open output file\n";
		exit(1);
	}

	std::string line;
	while (std::getline(_file, line)) {
		std::size_t pos = 0;
		
		while ((pos = line.find(_toSearch, pos)) != std::string::npos) {
			line.erase(pos, _toSearch.length());
			line.insert(pos, _toReplace);
			pos += _toReplace.length();
		}
		output << line << '\n';
	}
}
