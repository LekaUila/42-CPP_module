/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:34:42 by lflandri          #+#    #+#             */
/*   Updated: 2023/06/23 14:25:40 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BITCOINEXCHANGE
# define BITCOINEXCHANGE
# include <map>
# include <iostream>
# include <string>

class BitcoinExchange 
{
private:

	/* data */
	class DateBitcoin 
	{
	private:

		static const int month_day_tab[12];
		int	year;
		int month;
		int day;

	protected:

		/* data */

	public:

		DateBitcoin(std::string str);					//constructor
		~DateBitcoin();							//destructor
		DateBitcoin (const DateBitcoin &obj);				//copie constructor
		DateBitcoin& operator=(const DateBitcoin& x);		//assignation constructor
		int operator==(const DateBitcoin &other) const; //comparaison operator
		int operator<=(const DateBitcoin &other) const; 
		int operator>=(const DateBitcoin &other) const;
		int operator!=(const DateBitcoin &other) const;
		int operator>(const DateBitcoin &other) const;
		int operator<(const DateBitcoin &other) const;
		int	getYear() const;
		int	getMonth() const;
		int	getDay() const;

	
	};

	std::map<BitcoinExchange::DateBitcoin, double> data;

protected:

	/* data */

public:

	BitcoinExchange(/* args */);					//constructor
	~BitcoinExchange();							//destructor
	BitcoinExchange (const BitcoinExchange &obj);				//copie constructor
	BitcoinExchange& operator=(const BitcoinExchange& x);		//assignation constructor

 
};
#endif
