/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Data.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/27 17:15:28 by bfranco       #+#    #+#                 */
/*   Updated: 2023/09/03 17:26:39 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include <iostream>

Data::Data() : _name("John Doe"), _balance(0), _accountNumber(42069), _pinCode(1234)
{
	std::cout << "Default constructor called" << std::endl;
}
Data::Data(const Data &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Data::~Data()
{
	std::cout << "Destructor called" << std::endl;
}

Data&	Data::operator=(const Data& src)
{
	if (this != &src)
	{
		this->_name = src.getName();
		this->_balance = src.getBalance();
		this->_accountNumber = src.getAccountNumber();
		this->_pinCode = src.getPinCode();
	}
	return (*this);
}

std::string	Data::getName() const
{
	return (this->_name);
}

int			Data::getBalance() const
{
	return (this->_balance);
}

int			Data::getAccountNumber() const
{
	return (this->_accountNumber);
}

int			Data::getPinCode() const
{
	return (this->_pinCode);
}

std::ostream&	operator<<(std::ostream &out, const Data &src)
{
	out << "Name: " << src.getName() << std::endl;
	out << "Balance: " << src.getBalance() << std::endl;
	out << "Account number: " << src.getAccountNumber() << std::endl;
	out << "Pin code: " << src.getPinCode() << std::endl;
	return (out);
}
