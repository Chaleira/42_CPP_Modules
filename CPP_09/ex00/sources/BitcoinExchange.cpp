#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(char *filename)
{
	ExtractDataBase();
	ExtractFile(filename);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	*this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	(void)copy;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
	// std::cout << "BitcoinExchange destructor called" << std::endl;
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

void BitcoinExchange::ExtractFile(char *filename)
{
	std::ifstream file(filename);

	if (file.is_open())
	{
		std::string line, key, value;
		std::getline(file, line);
		while (std::getline(file, line))
		{
			std::stringstream linestream(line);
			std::getline(linestream, key, '|');
			std::getline(linestream, value);
			float val = atof(value.c_str());
			if (val < 0)
				std::cerr << "Error: not a positive number." << std::endl;
			else if (val > 1000)
				std::cerr << "Error: too large a number." << std::endl;
			else
				CompareData(key, val);
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

std::map<struct time, std::string>::iterator checkDateDistance(std::map<struct time, std::string>::iterator it, struct time time)
{
	std::map<struct time, std::string>::iterator checklenght = it;
	int lenght[2] = {0, 0};

	checklenght--;
	lenght[FRONT] = abs(it->first.tm_year - time.tm_year) * 365 + abs(it->first.tm_mon - time.tm_mon) * 30 + abs(it->first.tm_mday - time.tm_mday);
	lenght[BACK] = abs(checklenght->first.tm_year - time.tm_year) * 365 + abs(checklenght->first.tm_mon - time.tm_mon) * 30 + abs(checklenght->first.tm_mday - time.tm_mday);
	if (lenght[BACK] <= lenght[FRONT])
		return --it;
	return it;
}	

void BitcoinExchange::CompareData(std::string key, float value)
{
	struct time time;
	if (sscanf(key.c_str(), "%d-%d-%d", &time.tm_year, &time.tm_mon, &time.tm_mday) == 3 && validDate(time.tm_year, time.tm_mon, time.tm_mday))	
	{
		std::map<struct time, std::string>::iterator it = _dataBase.lower_bound(time);
		if (it == --_dataBase.end() || it == _dataBase.end())
			it--;
		else if (it->first > time && it != ++_dataBase.begin())
			it = checkDateDistance(it, time);
		std::cout << it->first.tm_year << "-" << it->first.tm_mon << "-" << it->first.tm_mday << " => ";
		std::cout << value << " = " << value * atof(it->second.c_str()) << std::endl;
	}
	else
		std::cerr << "Error: bad input => " << time.tm_year << "-" << time.tm_mon << "-" << time.tm_mday <<std::endl;
}
