#pragma once

# include <iostream>
# include <string>
# include <exception>
# include <map>
# include <fstream>
# include <sstream>
# include <cstdlib>
# include <cstring>


class timeCompare {

	int n;
	bool operator() (const struct tm& lhs, const struct tm& rhs);
};

class BitcoinExchange
{
	private:
		std::map<struct tm, std::string, timeCompare> _dataBase;
		std::map<struct tm, std::string, timeCompare> _inputData;

		void ExtractDataBase(void);
		void ExtractFile(char *filename);

	public:
		BitcoinExchange(char *filename);
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange &copy);
		~BitcoinExchange();

		void PrintDataBase(void);

};
