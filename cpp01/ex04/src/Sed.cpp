#include "Sed.hpp"

sed::sed(std::string filename, std::string toSearch, std::string toReplace)
{
	_file.open(filename.c_str());
	if (!_file.is_open())
	{
		std::cerr << "Error: could not input open file\n";
		exit(1);
	}

	_filename = filename;
	_toSearch = toSearch;
	_toReplace = toReplace;
}

sed::~sed()
{
	_file.close();
}

void sed::replace()
{
	std::ofstream output((_filename + ".replace").c_str());
	if (!output.is_open())
	{
		std::cerr << "Error: could not output open file\n";
		exit(1);
	}

	std::string line;
	while (std::getline(_file, line))
	{
		std::size_t pos = 0;
		while ((pos = line.find(_toSearch, pos)) != std::string::npos)
		{
			line.erase(pos, _toSearch.length());
			line.insert(pos, _toReplace);
			pos += _toReplace.length();
		}
		output << line << std::endl;
	}
}