/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 13:46:07 by bfranco       #+#    #+#                 */
/*   Updated: 2023/09/03 12:28:01 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

void	BitcoinExchange::_dataParser()
{
	std::ifstream		file("data.csv");
	std::string			line;
	std::string			date;
	double				rate;

	if (!file.is_open())
		throw (BitcoinExchange::InvalidDataBaseException());

	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::stringstream	ss(line);
		if (std::getline(ss, date, ',') && ss >> rate)
			this->_rateDB.insert(std::make_pair(date, rate));
	}
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange()
{
	try
	{
		this->_dataParser();
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

bool	isValidDate(std::string date)
{
	int	year;
	int	month;
	int	day;
	char			del;
	std::stringstream	ss(date);
	
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return (false);
	ss >> year >> del >> month >> del >> day;
	if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31)
		return (false);
	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day > 30)
			return (false);
	}
	else if (month == 2)
	{
		if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
		{
			if (day > 29)
				return (false);
		}
		else
		{
			if (day > 28)
				return (false);
		}
	}
	return (true);
}

double	findClosestDate(std::map<std::string, double> db, std::string date, double price)
{
	if (!isValidDate(date))
		throw (BitcoinExchange::InvalidDateException());
	if (price < 0)
		throw (BitcoinExchange::NegativeValueException());
	if (price > 1000)
		throw (BitcoinExchange::ValueTooLargeException());
	
	std::map<std::string, double>::iterator it = db.find(date);
	if (it == db.end())
	{
		it = db.lower_bound(date);
		if (it == db.begin())
			throw (BitcoinExchange::InvalidDateException());
		--it;
	}
	return (it->second);
}

void	BitcoinExchange::run(const std::string &inputFile)
{
	std::ifstream	file(inputFile);
	std::string		line;
	std::string		date;
	double			price;

	if (!file.is_open())
		throw (BitcoinExchange::InvalidDataBaseException());

	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::stringstream	ss(line);
		if (std::getline(ss, date, '|') && ss >> price)
		{
			date.erase(0, date.find_first_not_of(" \t\n\r\f\v"));
			date.erase(date.find_last_not_of(" \t\n\r\f\v") + 1);

			try
			{
				double	rate = findClosestDate(this->_rateDB, date, price);
				std::cout << date << " => " << price << " = " << price * rate << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << std::endl;
			}
		}
		else
			std::cerr << "Error: bad input => " << line << std::endl;
	}
}
