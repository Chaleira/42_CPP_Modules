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
		struct time time;
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
	for (std::map<struct time, std::string>::iterator it = _dataBase.begin(); it != _dataBase.end(); ++it)
	{
		std::cout << it->first.tm_year << "-" << it->first.tm_mon << "-" << it->first.tm_mday << " => " << it->second << std::endl;
	}
}

void BitcoinExchange::ExtractFile(char *filename)
{
	std::ifstream file(filename);

	if (file.is_open())
	{
		std::string line, key, value;
		while (std::getline(file, line))
		{
			std::stringstream linestream(line);
			std::getline(linestream, key, '|');
			std::getline(linestream, value);
			(void)CompareData(key);
		}
		file.close();
	}
	else
		throw std::runtime_error("Error: could not open file.");
}

bool validDate(int year, int month, int day)
{
	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;
	if (month == 2)
	{
		if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
			return day <= 29;
		return day <= 28;
	}
	if (month == 4 || month == 6 || month == 9 || month == 11)
		return day <= 30;
	return true;
}

bool BitcoinExchange::CompareData(std::string key)
{
	struct time time;
	if (sscanf(key.c_str(), "%d-%d-%d", &time.tm_year, &time.tm_mon, &time.tm_mday) == 3 && validDate(time.tm_year, time.tm_mon, time.tm_mday))	
	{
		std::map<struct time, std::string>::iterator it = _dataBase.lower_bound(time);
		if (it != _dataBase.begin() && it != ++_dataBase.begin() && it->first != time)
			it--;
		std::cout << it->first.tm_year << "-" << it->first.tm_mon << "-" << it->first.tm_mday << " => ";
		std::cout << it->second << std::endl;
		return true;
	}
	else
		std::cout << "Invalid date" << std::endl;
	return false;
}
