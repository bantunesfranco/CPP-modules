/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 13:46:07 by bfranco       #+#    #+#                 */
/*   Updated: 2023/09/02 19:55:57 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>

void	BitcoinExchange::_dataParser()
{
	std::ifstream	file("data.csv");
	std::string		line;
	std::string		amount;
	double			rate;

	if (!file.is_open())
		throw (BitcoinExchange::InvalidDataBaseException());

	std::getline(file, line);
	while (std::getline(file, line))
	{
		int index = line.find(',');
		if (index == static_cast<int>(std::string::npos))
			throw (BitcoinExchange::InvalidInputException(line));
			
		std::string	date = line.substr(0, index);

		try
		{
			amount = line.substr(index + 1, std::string::npos);
			rate = std::stod(amount);
			if (rate < 0)
				throw (BitcoinExchange::NegativeValueException());
			if (rate > INT32_MAX)
				throw (BitcoinExchange::ValueTooLargeException());
		}
		catch(const std::exception& e)
		{
			throw (BitcoinExchange::InvalidInputException(amount));
		}
		this->_rateDB.insert(std::make_pair(date, rate));
	}
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange()
{
	try
	{
		_dataParser();
	}
	catch(const std::exception& e)
	{
		std::cerr <<  e.what() << std::endl;
	}
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
	*this = src;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &src)
{
	if (this != &src)
	{
		_rateDB = src._rateDB;
		_priceDB = src._priceDB;
	}
	return (*this);
}

std::map<std::string, double>::iterator	findClosestDate(std::map<std::string, double> db, std::string date)
{
	std::map<std::string, double>::iterator it = db.find(date);
	
	if (it != db.end())
		return (it);
	else
	{
		
	}
}


void performCalculation(std::string date, double rate, double price)
{
	if (price < 0)
		throw (BitcoinExchange::NegativeValueException());
	if (price > 1000)
		throw (BitcoinExchange::ValueTooLargeException());
	
	std::cout << date << " => " << price << " = " << price * rate << std::endl;
}

void	BitcoinExchange::run()
{
	std::ifstream	file("input.csv");
	std::string		line;
	std::string		amount;
	double			price;

	if (!file.is_open())
		throw (BitcoinExchange::InvalidDataBaseException());

	std::getline(file, line);
	while (std::getline(file, line))
	{
		try
		{
			int index = line.find(',');
			if (index == std::string::npos)
				throw (BitcoinExchange::InvalidInputException(line));
				
			std::map<std::string, double>::iterator	date = findClosestDate(this->_rateDB, line.substr(0, index));
			amount = line.substr(index + 1, std::string::npos);
			try
			{
				price = std::stod(amount);
			}
			catch(const std::exception& e)
			{
				throw (BitcoinExchange::InvalidInputException(amount));
			}
			performCalculation(date->first , date->second, price);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}
