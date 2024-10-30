#include "DefineTypes.hpp"

bool	isChar(std::string str) {
	return (str.length() == 1 && isprint(str[0]) && !isdigit(str[0]));
}

bool	isInt(std::string str) {
	std::istringstream iss(str);
	int i;

	iss >> i;
	if (iss.fail() || !iss.eof()) {
		return (false);
	}
		
	return (true);
}

bool	isFloat(std::string str) {
	char* end;
	errno = 0;
	double f = strtod(str.c_str(), &end);

	if (f > std::numeric_limits<float>::max()
		|| f < -std::numeric_limits<float>::max()
		|| end == str.c_str()
		|| *end != 'f'
		|| *(end + 1) != '\0') {
		return (false);
	}

	return (true);
}

bool	isDouble(std::string str) {
	char* end;
	errno = 0;
	strtod(str.c_str(), &end);

	if (errno == ERANGE || end == str.c_str() || *end != '\0') {
		return (false);
	}

	return (true);
}
