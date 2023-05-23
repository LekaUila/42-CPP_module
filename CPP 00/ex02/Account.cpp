/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:57:33 by lflandri          #+#    #+#             */
/*   Updated: 2022/12/06 17:44:56 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <string>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

static void ft_print_date(void)
{
	time_t now = time(0);
   std::tm *date = localtime(&now);
   std::cout << "[" << date->tm_year + 1900;

	if (date->tm_mon + 1 < 10)
		std::cout << "0";
	std::cout << date->tm_mon + 1;

	if (date->tm_mday < 10)
		std::cout << "0";
	std::cout << date->tm_mday << "_";

	if (date->tm_hour < 10)
		std::cout << "0";
	std::cout << date->tm_hour;

	if (date->tm_min < 10)
		std::cout << "0";
	std::cout << date->tm_min;

	if (date->tm_sec < 10)
		std::cout << "0";
	std::cout << date->tm_sec << "] ";
}


int	Account::getNbAccounts( void )
{
	return Account::_nbAccounts;
}

int Account::getTotalAmount( void )
{
	return Account::_totalAmount;
}

int	Account::getNbDeposits( void )
{
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
	return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos( void )
{
	ft_print_date();
	std::cout << "accounts:" << Account::getNbAccounts() << ";total:" << 
	Account::getTotalAmount() << ";deposits:" << Account::getNbDeposits()
	<< ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
	
}

Account::Account( int initial_deposit )
:	_accountIndex(Account::_nbAccounts),
	_amount(initial_deposit),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	Account::_nbAccounts++;
	Account::_totalAmount+= initial_deposit;
	ft_print_date();
	std::cout << "index:" << this->_accountIndex << ";amount:" << 
	this->_amount << ";created" << std::endl;
}

Account::~Account( void )
{
	ft_print_date();
	std::cout << "index:" << this->_accountIndex << ";amount:" << 
	this->_amount << ";closed" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	ft_print_date();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << 
	this->_amount << ";deposit:" << deposit << ";amount:" << 
	this->_amount + deposit << ";deposits:" << this->_nbDeposits + 1 << std::endl;
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	ft_print_date();
	if (this->_amount - withdrawal < 0)
	{
		std::cout << "index:" << this->_accountIndex << ";p_amount:" << 
		this->_amount << ";withdrawal:refused" << std::endl;
		return (false);
	}
	else
	{
		ft_print_date();
		std::cout << "index:" << this->_accountIndex << ";p_amount:" << 
		this->_amount << ";withdrawal:" << withdrawal << ";amount:" << 
		this->_amount - withdrawal << ";withdrawals:" << this->_nbWithdrawals + 1 << std::endl;
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalNbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		return (true);
	}
}

int		Account::checkAmount( void ) const
{
	return this->_amount;
}

void	Account::displayStatus( void ) const
{
	ft_print_date();
	std::cout << "index:" << this->_accountIndex << ";amount:" << 
	this->_amount << ";deposits:" << this->_nbDeposits <<
	";withdrawals:" << this->_nbWithdrawals << std::endl;
}
