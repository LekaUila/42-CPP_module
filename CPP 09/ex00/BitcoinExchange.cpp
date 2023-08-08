/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:34:45 by lflandri          #+#    #+#             */
/*   Updated: 2023/08/08 17:00:12 by lflandri         ###   ########.fr       */
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
    if (!datafile.is_open())
    {
        std::string err_str = "BitcoinExchange ||EXEPTION|| : can't access csv database (\"";
        err_str += DATA_FILENAME;
        err_str += "\")";
        throw std::runtime_error((const char *)err_str.c_str());
    }

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
		separator = BitcoinExchange::getSeparatorDateValue(line, "exchange_rate");
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
				size_t sep_pos = line.find(separator);
                if (sep_pos == std::string::npos)
                    throw std::invalid_argument("BitcoinExchange ||EXEPTION|| : can't find a separator who math the actual separator");
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
		i = pos + (pos != std::string::npos);
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

std::string BitcoinExchange::getSeparatorDateValue(std::string str, std::string snd_name)
{
	size_t date_pos = 0;
	size_t value_pos = 0;
	char tab[999];

	date_pos = str.find("date", 0);
	value_pos = str.find(snd_name, 0);
	if (date_pos == std::string::npos || value_pos == std::string::npos || date_pos + 4 >= value_pos)
	{
		throw std::invalid_argument("BitcoinExchange ||EXEPTION|| : invalid format of separator");
	}
	if (value_pos - (date_pos + 4) > 990)
		throw std::invalid_argument("BitcoinExchange ||EXEPTION|| : separator to long");
	str.copy(tab, value_pos - (date_pos + 4), 4);
    tab[value_pos - (date_pos + 4)] = 0;
    if (BitcoinExchange::DateBitcoin::hasDateCharacters(tab))
       throw std::invalid_argument("BitcoinExchange ||EXEPTION|| : invalid format of separator");
	return (tab);
}

void BitcoinExchange::printLigne(const std::pair<BitcoinExchange::DateBitcoin, double> &p)
{
    std::cout << "{" << p.first.getYear()<< "-" << p.first.getMonth()<< "-" << p.first.getDay()  << " : " << p.second << "}" << std::endl;
}

void BitcoinExchange::printData() const
{
    std::for_each(this->data.begin(), this->data.end(), BitcoinExchange::printLigne);
}

void BitcoinExchange::exchange(char * filename) const
{
    std::ifstream datafile(filename, std::ios::in);
    if (!datafile.is_open())
    {
        std::string err_str = "Error: could not open file.";
        throw std::runtime_error((const char *)err_str.c_str());
    }
	std::string line = "";
	std::string separator;
    std::map<BitcoinExchange::DateBitcoin, double> input_data;
    
	char c = 42;
	
	while (datafile.get(c))
	{
		line +=c;
		if (c == '\n')
			break;
	}
	try
	{
		separator = BitcoinExchange::getSeparatorDateValue(line, "value");
	}
	catch(const std::exception& e)
	{
		datafile.close();
		throw std::invalid_argument(e.what());
	}

	while (datafile)
	{
	    line = "";
        std::getline(datafile, line);
        if (!line.empty())
        {
			try
			{
                std::map<BitcoinExchange::DateBitcoin, double>::const_iterator logic_data;
				std::string date = "";
				std::string value = "";
				size_t sep_pos = line.find(separator);
                if (sep_pos == std::string::npos)
                {
                    std::string error_str = "Error: bad input => ";
                    error_str += line;
                    throw std::invalid_argument(error_str);
                }
				date = line;
				date.erase(sep_pos, std::string::npos);
				value = line;
				value.erase(0, sep_pos + separator.size());
                try
                {
                    BitcoinExchange::DateBitcoin date_o(date);
                }
                catch(const std::exception& e)
                {
                    std::string error_str = "Error: bad input => ";
                    error_str += line;
                    throw std::invalid_argument(error_str);
                }
                
				BitcoinExchange::DateBitcoin date_o(date);
                double value_d = 0.0;
                try
                {
                    value_d = this->convertValueData(value);
                }
                catch(const std::exception& e)
                {
                    throw std::invalid_argument("Error: not a positive number");
                }
                if (value_d > INT32_MAX)
                    throw std::invalid_argument("Error: too large a number.");
                input_data[date_o] = value_d;
                logic_data = this->data.lower_bound(date_o);
                if (logic_data == this->data.end())
                {
                    std::string error_str = "Error: No argument to match => ";
                    error_str += date;
                    throw std::invalid_argument(error_str);
                }
                if (SHOW_LOGIC_DATA)
                {
                                std::cout << "logic data : " << logic_data->first.getYear()<< "-" << logic_data->first.getMonth() << "-"
                        << logic_data->first.getDay
                        () << " | " << logic_data->second << std::endl;        
                }
                std::cout << date << " => " <<  value_d << " = " << value_d * logic_data->second << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << std::endl;
			}
			line = "";
		}
    }
}

/*=========================BitcoinExchange::DateBitcoin=========================*/


BitcoinExchange::DateBitcoin::DateBitcoin(std::string str)
{
	if (!BitcoinExchange::DateBitcoin::strIsADateFormat(str))
		throw std::invalid_argument("BitcoinExchange::DateBitcoin ||EXEPTION|| : invalid format");
	std::string year = "";
	std::string month = "";
	std::string day = "";
	char tab1[999] = {0};
    char tab2[999] = {0};
    char tab3[999] = {0};
	size_t i = 0;
	size_t n_pos;
    int neg = 1;
	if (str.at(i) == '-')
	{
		i++;
        neg = -1;
	}
	n_pos = str.find("-",i) + 1;
	if (n_pos - i > 990)
		throw std::invalid_argument("BitcoinExchange::DateBitcoin ||EXEPTION|| : line to long : " + str);
	str.copy(tab1, n_pos - i, i);
	year = tab1;
	i = n_pos;
	n_pos = str.find("-",i) + 1;
	if (n_pos - i > 990)
		throw std::invalid_argument("BitcoinExchange::DateBitcoin ||EXEPTION|| : line to long : " + str);
	str.copy(tab2, n_pos - i, i);
	month = tab2;
	i = n_pos;
	if (n_pos - i > 990)
		throw std::invalid_argument("BitcoinExchange::DateBitcoin ||EXEPTION|| : line to long : " + str);
	str.copy(tab3, str.size() - i, i);
	day = tab3;  
	this->day = atoi(day.c_str());
	this->month = atoi(month.c_str());
	this->year = atoi(year.c_str());  
	this->year *= neg;
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

int BitcoinExchange::DateBitcoin::operator>=(const BitcoinExchange::DateBitcoin &other) const
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
int BitcoinExchange::DateBitcoin::operator<=(const BitcoinExchange::DateBitcoin &other) const
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
int BitcoinExchange::DateBitcoin::operator<(const BitcoinExchange::DateBitcoin &other) const
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
int BitcoinExchange::DateBitcoin::operator>(const BitcoinExchange::DateBitcoin &other) const
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

bool BitcoinExchange::DateBitcoin::hasDateCharacters(std::string str)
{
	size_t i = 0;
   
	while (i != str.size())
	{
		if (isNumber(str.at(i)) || str.at(i) == '-')
        {
            return (true);
        }
		i++;
	}
	
	return (false);
}

bool BitcoinExchange::DateBitcoin::strIsADateFormat(std::string str)
{
	if (!BitcoinExchange::DateBitcoin::hasOnlyDateCharacters(str) or str.empty())
		return (false);
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
	n_pos = str.find("-",i);
	if (n_pos == std::string::npos)
		return (false);
	i = n_pos;
	n_pos = str.find("-",i);
	if (n_pos == i + 1 || n_pos == std::string::npos)
		return (false);
	return (true);
}
