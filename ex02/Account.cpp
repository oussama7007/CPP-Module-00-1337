/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:17:34 by oait-si-          #+#    #+#             */
/*   Updated: 2025/10/20 18:46:06 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"


	int Account::_nbAccounts = 0;
	int Account::_totalAmount = 0;
	int	Account::_totalNbDeposits = 0;
	int Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp( void )
{
	std::time_t t = std::time(NULL);
    std::tm *now = std::localtime(&t);

    std::cout << '['
              << (now->tm_year + 1900)
              << std::setw(2) << std::setfill('0') << (now->tm_mon + 1)
              << std::setw(2) << std::setfill('0') << now->tm_mday
              << '_'
              << std::setw(2) << std::setfill('0') << now->tm_hour
              << std::setw(2) << std::setfill('0') << now->tm_min
              << std::setw(2) << std::setfill('0') << now->tm_sec
              << "] ";
    std::cout << std::setfill(' ');
}


Account::Account(int  initial_deposit)
{
        this->_accountIndex = _nbAccounts;
        this->_amount = initial_deposit;
        this->_nbDeposits = 0;
        this->_nbWithdrawals = 0;
        _nbAccounts++;
        _totalAmount += initial_deposit;
        _displayTimestamp();
        std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

int     Account::checkAmount(void) const
{
    return this->_amount;
}
int    Account::getNbAccounts(void)
{
        return _nbAccounts;
}

int Account::getTotalAmount(void)
{
        return _totalAmount;
}

int Account::getNbWithdrawals(void)
{
        return _totalNbWithdrawals;
}

int     Account::getNbDeposits(void)
{
        return _totalNbDeposits;
}

void	Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts()
              << ";total:" << getTotalAmount()
              << ";deposits:" << getNbDeposits()
              << ";withdrawals:" << getNbWithdrawals()
              << std::endl;
}

void    Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";amount:" << this->_amount
              << ";deposits:" << this->_nbDeposits
              << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

bool    Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout << "index:" <<  this->_accountIndex
              << ";p_amount:" << this->_amount;
    if(withdrawal > this->_amount)
    {
        std::cout << ";withdrawal:refused" << std::endl;
        return false;
    }
    this->_amount -= withdrawal;
    this->_nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;

    std::cout << ";withdrawal:" << withdrawal
              << ";amount:" << this->_amount
              << ";nb_withdrawals:" << this->_nbWithdrawals
              << std::endl;
    return true;
}

void    Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex
                << ";p_amount:" << this->_amount
                << ";deposit:" << deposit;
    this->_amount += deposit;
    this->_nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;
    std::cout << ";amount:" << this->_amount
                << ";nb_deposits:" << this->_nbDeposits
                << std::endl; 
}
Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}