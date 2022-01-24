/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 00:10:12 by spoliart          #+#    #+#             */
/*   Updated: 2022/01/25 00:28:27 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Account.hpp"

Account::Account( void )
{
	Account::_nbAccounts += 1;
	return ;
}

Account::Account( int initial_deposit )
{
	Account::_nbAccounts += 1;
	makeDeposit(initial_deposit);
	return ;
}

Account::~Account( void )
{
	Account::_nbAccounts -= 1;
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
	std::cout << "Account index: " << this->_accountIndex << std::endl;
	std::cout << "Amount: " << this->_amount << std::endl;
	std::cout << "Number of deposit: " << this->_nbDeposits << std::endl;
	std::cout << "Number of withdrawals: " << this->_nbWithdrawals << std::endl;
	return ;
}

void	Account::makeDeposit( int deposit )
{
	this->_amount += deposit;
	this->_nbDeposits += 1;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits += 1;
	return ;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (this->_amount < withdrawal)
		return false;
	this->_amount -= withdrawal;
	this->_nbWithdrawals += 1;
	Account::_totalNbWithdrawals += 1;
	Account::_totalAmount -= withdrawal;
	return true;
}
