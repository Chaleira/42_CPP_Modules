#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(char *filename)
{
	ExtractDataBase();
	ExtractFile(filename);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	_dataBase = copy._dataBase;
	*this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	_dataBase = copy._dataBase;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::ExtractDataBase(void)
{
	std::ifstream file("data.csv");

	if (file.is_open())
	{
		struct time time;
		std::string line, key, value;
		std::getline(file, line);
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

void BitcoinExchange::ExtractFile(char *filename)
{
	std::ifstream file(filename);

	if (file.is_open())
	{
		std::string line;
		std::getline(file, line);
		while (std::getline(file, line))
		{
			struct time time;
			double value;
			char c = 0;
			if (sscanf(line.c_str(), "%d-%d-%d | %lf%c", &time.tm_year, &time.tm_mon, &time.tm_mday, &value, &c) == 4)
			{
				if (!validDate(time.tm_year, time.tm_mon, time.tm_mday))
					std::cerr << "Error: bad input => " << time.tm_year << "-" << time.tm_mon << "-" << time.tm_mday << std::endl;
				else if (value < 0)
					std::cerr << "Error: not a positive number." << std::endl;
				else if (value > 1000)
					std::cerr << "Error: too large a number." << std::endl;
				else
					CompareData(time, value);
			}
			else
				std::cerr << "Error: bad input => " << line << std::endl;
		}
		file.close();
	}
	else
		throw std::runtime_error("Error: could not open file.");
}

void BitcoinExchange::CompareData(struct time time, double value)
{
	std::map<struct time, std::string>::iterator it = _dataBase.lower_bound(time);
		if (it != _dataBase.begin() && it->first != time)
			it--;
		// std::cout << it->first.tm_year << "-" << it->first.tm_mon << "-" << it->first.tm_mday << " => ";
		std::cout << time.tm_year << "-" << time.tm_mon << "-" << time.tm_mday << " => ";
		if (static_cast<int>(value) - value == 0)
			std::cout << static_cast<int>(value) << " = " << value * atof(it->second.c_str()) << std::endl;
		else
			std::cout << std::fixed << std::setprecision(2) << value << " = " << value * atof(it->second.c_str()) << std::endl;
}
