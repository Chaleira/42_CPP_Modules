#pragma once

# include <iostream>
# include <string>
# include <exception>
# include <map>
# include <fstream>
# include <sstream>
# include <cstdlib>
# include <cstring>

struct time
{
	int tm_year;
	int tm_mon;
	int tm_mday;

	bool operator<(const time &rhs) const
	{
		if (tm_year < rhs.tm_year)
			return true;
		else if (tm_year == rhs.tm_year)
		{
			if (tm_mon < rhs.tm_mon)
				return true;
			else if (tm_mon == rhs.tm_mon)
			{
				if (tm_mday < rhs.tm_mday)
					return true;
			}
		}
		return false;
	}

	bool operator!=(const time &rhs) const
	{
		if (tm_year != rhs.tm_year || tm_mon != rhs.tm_mon || tm_mday != rhs.tm_mday)
			return true;
		return false;
	}
};

class BitcoinExchange
{
	private:
		std::map<struct time, std::string> _dataBase;

		void ExtractDataBase(void);
		void ExtractFile(char *filename);

	public:
		BitcoinExchange(char *filename);
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange &copy);
		~BitcoinExchange();

		void PrintDataBase(void);
		bool CompareData(std::string key);

};
