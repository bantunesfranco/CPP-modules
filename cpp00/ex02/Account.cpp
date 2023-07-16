/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Account.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/09 17:44:19 by bfranco       #+#    #+#                 */
/*   Updated: 2023/07/16 14:45:31 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

// Init static member attributes
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Default Contructor
Account::Account( void ){}

// Constuctor
Account::Account( int initial_deposit )
{
	static int i = 0;
	
	this->_accountIndex = i;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount+= initial_deposit;
	i++;

	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->checkAmount() << ";created" << std::endl;
}

// Destructor
Account::~Account( void )
{
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->checkAmount() << ";closed" << std::endl;
}


// Static Public Methods
int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << " accounts:" << Account::getNbAccounts() << ";total:" << Account::getTotalAmount() \
	<< ";deposits:" << Account::getNbDeposits() << ";withdrawals:" << Account::getNbWithdrawals() \
	<< std::endl;
}


// Static Private Methods
void	Account::_displayTimestamp( void )
{
	time_t	now = time(0);
	tm 		*ltm = localtime(&now);
	
	std::cout << "[";
	std::cout << ltm->tm_year + 1900;
	if (ltm->tm_mon < 10)
		std::cout << "0";
	std::cout << ltm->tm_mon + 1;
	if (ltm->tm_mday < 10)
		std::cout << "0";
	std::cout << ltm->tm_mday;
	std::cout << "_";
	if (ltm->tm_hour < 10)
		std::cout << "0";
	std::cout << ltm->tm_hour + 2;
	if (ltm->tm_min < 10)
		std::cout << "0";
	std::cout << ltm->tm_min;
	if (ltm->tm_sec < 10)
		std::cout << "0";
	std::cout << ltm->tm_sec;
	std::cout << "]";
}


// Public methods
void Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->checkAmount();
	this->_amount += deposit;
	this->_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout << ";deposit:" << deposit << ";amount:" << this->checkAmount() \
	<< ";nb_deposits:" << this->_nbDeposits  << std::endl;
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

bool	Account::makeWithdrawal( int withdrawal )
{
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->checkAmount();
	if (withdrawal >= this->checkAmount())
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	std::cout << ";withdrawal:" << withdrawal << ";amount:" << this->checkAmount() \
	<< ";nb_withdrawals:" << this->_nbWithdrawals  << std::endl;
	return (true);
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->checkAmount() \
	<< ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals \
	<< std::endl;
}