#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(char *filename)
{
	ExtractDataBase();
	std::cout << "=======================" << std::endl;
	ExtractFile(filename);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	// Don't forget to copy the variables here
	*this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	(void)copy;
	// Don't forget to copy the variables here
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "BitcoinExchange destructor called" << std::endl;
}

void BitcoinExchange::ExtractDataBase(void)
{
	std::ifstream file("data.csv");

	if (file.is_open())
	{
		struct tm time;
		std::string line, key, value;
		while (std::getline(file, line))
		{
			std::stringstream linestream(line);
			std::getline(linestream, key, ',');
			sscanf(key.c_str(), "%d-%d-%d", &time.tm_year, &time.tm_mon, &time.tm_mday);
			std::getline(linestream, value);
			_dataBase.insert(std::make_pair(time, value));
		}
		file.close();
	}
	else
		throw std::runtime_error("Error: could not access data Base.");
}

void BitcoinExchange::PrintDataBase(void)
{
	for (std::map<struct tm, std::string>::iterator it = _dataBase.begin(); it != _dataBase.end(); ++it)
	{
		std::cout << it->first.tm_year << "-" << it->first.tm_mon << "-" << it->first.tm_mday << " => " << it->second << std::endl;
	}
}

void BitcoinExchange::ExtractFile(char *filename)
{
	std::ifstream file(filename);

	_dataBase.key_comp().n;
	if (file.is_open())
	{
		std::string line, key, value;
		struct tm time;
		while (std::getline(file, line))
		{
			std::stringstream linestream(line);
			std::getline(linestream, key, '|');
			std::getline(linestream, value);
			std::cout << "year: " << key << std::endl;
			bzero(&time, sizeof(time));
			if (sscanf(key.c_str(), "%d-%d-%d", &time.tm_year, &time.tm_mon, &time.tm_mday))
			{
				std::cout << "1" << std::endl;
				std::map<struct tm, std::string, timeCompare>::iterator it = _dataBase.find(time);
				std::cout << "2" << std::endl;
				if (it == _dataBase.end())
					std::cout << "No data" << std::endl;
				else
					std::cout << "it->first.tm_year: " << it->first.tm_year << std::endl;
			}
			else
				std::cout << "Invalid date" << std::endl;
			std::cout << std::endl;
		}
		file.close();
	}
	else
		throw std::runtime_error("Error: could not open file.");
}

bool timeCompare::operator()(const struct tm &lhs, const struct tm &rhs)
{
	std::cout << "timeCompare called" << std::endl;

	this->n = 1;
	if (lhs.tm_year != rhs.tm_year)
		return lhs.tm_year < rhs.tm_year;
	if (lhs.tm_mon != rhs.tm_mon)
		return lhs.tm_mon < rhs.tm_mon;
	return lhs.tm_mday < rhs.tm_mday;
}