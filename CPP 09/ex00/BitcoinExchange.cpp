/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:34:45 by lflandri          #+#    #+#             */
/*   Updated: 2023/06/23 14:51:34 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "BitcoinExchange.hpp"

const int BitcoinExchange::DateBitcoin::month_day_tab[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

BitcoinExchange::BitcoinExchange(/* args */)
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange (const BitcoinExchange &obj)
{
	(void) obj;
}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& x)
{
	(void) x;
	return (*this);
}





BitcoinExchange::DateBitcoin::DateBitcoin(std::string str)
{
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