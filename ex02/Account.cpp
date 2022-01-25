/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 00:10:12 by spoliart          #+#    #+#             */
/*   Updated: 2022/01/25 14:43:42 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Account.hpp"

#define RESET	"\033[0m"
#define BOLD	"\033[1m"
#define RED		"\033[31m"
#define BLUE	"\033[34m"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( void )
{
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_nbAccounts += 1;
	return ;
}

Account::Account( int initial_deposit )
{
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_nbAccounts += 1;
	makeDeposit(initial_deposit);
	return ;
}

Account::~Account( void )
{
	this->_nbAccounts -= 1;
	return ;
}

int	Account::getNbAccounts( void )
{
	return Account::_nbAccounts;
}

int	Account::getTotalAmount( void )
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

void	Account::displayAccountsInfos( void )
{
	std::cout << std::endl << BLUE;
	std::cout << "Total number of accounts: " << Account::_nbAccounts << std::endl;
	std::cout << "Total amount: " << Account::_totalAmount << std::endl;
	std::cout << "Total number of deposits: " << Account::_totalNbDeposits << std::endl;
	std::cout << "Total number of withdrawal: " << Account::_totalNbWithdrawals << std::endl;
	std::cout << RESET;
	return ;
}

void	Account::makeDeposit( int deposit )
{
	if (deposit < 0) {
		std::cout << BOLD << RED << "Canno't deposit negative number" << RESET << std::endl;
		return ;
	}
	this->_amount += deposit;
	this->_nbDeposits += 1;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits += 1;
	return ;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (this->_amount < withdrawal) {
		std::cout << BOLD << RED << "Canno't withdrawal more than account amount" << RESET << std::endl;
		return false;
	}
	if (withdrawal < 0) {
		std::cout << BOLD << RED << "Canno't withdrawal negative number" << RESET << std::endl;
		return false;
	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals += 1;
	Account::_totalNbWithdrawals += 1;
	Account::_totalAmount -= withdrawal;
	return true;
}

int	Account::checkAmount( void ) const
{
	return this->_amount;
}

void	Account::displayStatus( void ) const
{
	std::cout << std::endl;
	std::cout << "Account index: " << this->_accountIndex << std::endl;
	std::cout << "Account amount: " << this->_amount << std::endl;
	std::cout << "Number of deposits: " << this->_nbDeposits << std::endl;
	std::cout << "Number of withdrawal: " << this->_nbWithdrawals << std::endl;
	return ;
}
