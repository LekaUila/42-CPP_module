/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:34:45 by lflandri          #+#    #+#             */
/*   Updated: 2023/07/11 13:10:35 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

const int BitcoinExchange::DateBitcoin::month_day_tab[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

static bool isNumber(char c)
{
	return (!(c < '0' || c  > '9'));
}

/*===============================BitcoinExchange===============================*/

BitcoinExchange::BitcoinExchange()
{
	std::ifstream datafile(DATA_FILENAME, std::ios::in);
	std::string line = "";
	std::string separator;
	char c = 42;
	
	while (datafile.get(c))
	{
		line +=c;
		if (c == '\n')
			break;
	}
	try
	{
		BitcoinExchange::getSeparatorDateValue(line);
	}
	catch(const std::exception& e)
	{
		datafile.close();
		throw std::invalid_argument(e.what());
	}
	line = "";
	while (datafile.get(c))
	{
		
		if (c == '\n')
		{
			try
			{
				std::string date = "";
				std::string value = "";
				int sep_pos = line.find(separator);
				date = line;
				date.erase(sep_pos, std::string::npos);
				value = line;
				value.erase(0, sep_pos + separator.size());

				BitcoinExchange::DateBitcoin date_o(date);
				double value_d = this->convertValueData(value);
				this->data[date_o] = value_d;
			}
			catch(const std::exception& e)
			{
				datafile.close();
				throw std::invalid_argument(e.what());
			}
			line = "";
		}
		else
			line += c;
	}
}

double BitcoinExchange::convertValueData(std::string value)
{
	size_t i = 0;
	int count_p = 0;
	while (i < value.size())
	{
		size_t pos = value.find(".", i);
		if (pos != std::string::npos)
			count_p++;
		if (count_p > 1)
			throw std::invalid_argument("BitcoinExchange::DateBitcoin ||EXEPTION|| : invalid value");
		i = pos;
	}
	i = 0;
	while (i != value.size())
	{
		if (!isNumber(value.at(i)) && value.at(i) != '.')
			throw std::invalid_argument("BitcoinExchange::DateBitcoin ||EXEPTION|| : invalid value");
		i++;
	}
	
	return (atof(value.c_str()));
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange (const BitcoinExchange &obj)
{
	this->data = obj.data;
}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& x)
{
	this->data = x.data;
	return (*this);
}

std::string BitcoinExchange::getSeparatorDateValue(std::string str)
{
	size_t date_pos = 0;
	size_t value_pos = 0;
	char tab[999];

	date_pos = str.find("date", 0);
	value_pos = str.find("exchange_rate", 0);
	if (date_pos == std::string::npos || value_pos == std::string::npos || date_pos + 4 >= value_pos)
	{
		throw std::invalid_argument("BitcoinExchange ||EXEPTION|| : invalid format of separator");
	}
	if (value_pos - (date_pos + 4) > 990)
		throw std::invalid_argument("BitcoinExchange ||EXEPTION|| : separator to long");
	str.copy(tab, value_pos - (date_pos + 4));
	return (tab);
}

/*=========================BitcoinExchange::DateBitcoin=========================*/


BitcoinExchange::DateBitcoin::DateBitcoin(std::string str)
{
	if (!BitcoinExchange::DateBitcoin::strIsADateFormat(str))
		throw std::invalid_argument("BitcoinExchange::DateBitcoin ||EXEPTION|| : invalid format");
	std::string year = "";
	std::string month = "";
	std::string day = "";
	char tab[999] = {0};
	size_t i = 0;
	size_t n_pos;
	if (str.at(i) == '-')
	{
		i++;
	}
	n_pos = str.find("-",i);
	if (n_pos - i > 990)
		throw std::invalid_argument("BitcoinExchange::DateBitcoin ||EXEPTION|| : line to long : " + str);
	str.copy(tab, n_pos - i, i);
	year = tab;
	i = n_pos;
	n_pos = str.find("-",i);
	if (n_pos - i > 990)
		throw std::invalid_argument("BitcoinExchange::DateBitcoin ||EXEPTION|| : line to long : " + str);
	str.copy(tab, n_pos - i, i);
	month = tab;
	i = n_pos;
	if (n_pos - i > 990)
		throw std::invalid_argument("BitcoinExchange::DateBitcoin ||EXEPTION|| : line to long : " + str);
	str.copy(tab, str.size() - i, i);
	day = tab;
	this->day = atoi(day.c_str());
	this->month = atoi(month.c_str());
	this->year = atoi(year.c_str());
	if (str.at(i) == '-')
		this->year *= -1;
	if (this->month < 1 || this->month > 12)
		throw std::invalid_argument("BitcoinExchange::DateBitcoin ||EXEPTION|| : invalid month");
	if (this->month != 2 || this->year % 4)
	{
		if (this->day < 1 || this->day > BitcoinExchange::DateBitcoin::month_day_tab[this->month - 1])
			throw std::invalid_argument("BitcoinExchange::DateBitcoin ||EXEPTION|| : invalid day");
	}
	else
	{
		if (this->day < 1 || this->day > 29)
			throw std::invalid_argument("BitcoinExchange::DateBitcoin ||EXEPTION|| : invalid day");
	}
}

BitcoinExchange::DateBitcoin::~DateBitcoin()
{
}

BitcoinExchange::DateBitcoin::DateBitcoin(const BitcoinExchange::DateBitcoin &obj)
{
	this->day = obj.getDay();
	this->year = obj.getYear();
	this->month = obj.getMonth();
}
BitcoinExchange::DateBitcoin& BitcoinExchange::DateBitcoin::operator=(const BitcoinExchange::DateBitcoin& x)
{
	this->day = x.getDay();
	this->year = x.getYear();
	this->month = x.getMonth();
	return (*this);
}

int BitcoinExchange::DateBitcoin::operator==(const BitcoinExchange::DateBitcoin &other) const
{
	return (this->year == other.getYear() && this->day == other.getDay() && this->month == other.getMonth());
}

int BitcoinExchange::DateBitcoin::operator<=(const BitcoinExchange::DateBitcoin &other) const
{
	if (this->year < other.getYear())
		return (1);
	else if (this->year > other.getYear())
		return (0);
	if (this->month < other.getMonth())
		return (1);
	else if (this->month > other.getMonth())
		return (0);
	if (this->day <= other.getDay())
		return (1);
	return (0);
}
int BitcoinExchange::DateBitcoin::operator>=(const BitcoinExchange::DateBitcoin &other) const
{
	if (this->year > other.getYear())
		return (1);
	else if (this->year < other.getYear())
		return (0);
	if (this->month > other.getMonth())
		return (1);
	else if (this->month < other.getMonth())
		return (0);
	if (this->day >= other.getDay())
		return (1);
	return (0);
}
int BitcoinExchange::DateBitcoin::operator!=(const BitcoinExchange::DateBitcoin &other) const
{
	return (this->year != other.getYear() || this->day != other.getDay() || this->month != other.getMonth());
}
int BitcoinExchange::DateBitcoin::operator>(const BitcoinExchange::DateBitcoin &other) const
{
	if (this->year > other.getYear())
		return (1);
	else if (this->year < other.getYear())
		return (0);
	if (this->month > other.getMonth())
		return (1);
	else if (this->month < other.getMonth())
		return (0);
	if (this->day > other.getDay())
		return (1);
	return (0);
}
int BitcoinExchange::DateBitcoin::operator<(const BitcoinExchange::DateBitcoin &other) const
{
	if (this->year < other.getYear())
		return (1);
	else if (this->year > other.getYear())
		return (0);
	if (this->month < other.getMonth())
		return (1);
	else if (this->month > other.getMonth())
		return (0);
	if (this->day < other.getDay())
		return (1);
	return (0);
}

int	BitcoinExchange::DateBitcoin::getYear() const
{
	return (this->year);
}
int	BitcoinExchange::DateBitcoin::getMonth() const
{
	return (this->month);
}
int	BitcoinExchange::DateBitcoin::getDay() const
{
	return (this->day);
}

bool BitcoinExchange::DateBitcoin::hasOnlyDateCharacters(std::string str)
{
	size_t i = 0;
	while (i != str.size())
	{
		if (!isNumber(str.at(i)) && str.at(i) != '-')
			return (false);
		i++;
	}
	
	return (true);
}

bool BitcoinExchange::DateBitcoin::strIsADateFormat(std::string str)
{
	if (!BitcoinExchange::DateBitcoin::hasOnlyDateCharacters(str) or str.empty())
		return (false);
	std::cout << "test1" << std::endl;
	size_t i = 0;
	size_t n_pos;
	if (str.at(i) == '-' && str.at(i + 1) != '-')
	{
		i++;
	}
	else if (str.at(i) == '-' && str.at(i + 1) == '-')
	{
		return (false);
	}
	std::cout << "test2" << std::endl;
	n_pos = str.find("-",i);
	if (n_pos == std::string::npos)
		return (false);
	std::cout << "test3" << std::endl;
	i = n_pos;
	n_pos = str.find("-",i);
	if (n_pos == i + 1 || n_pos == std::string::npos)
		return (false);
	std::cout << "test4" << std::endl;
	i = n_pos;
	n_pos = str.find("-",i);
	if (n_pos != std::string::npos)
		return (false);
	std::cout << "test5" << std::endl;
	return (true);
}