/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 13:46:07 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/31 18:28:01 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>

BitcoinExchange::s_date	createDate(std::string line)
{
	BitcoinExchange::s_date	date;

	date.year = std::stoi(line.substr(0, line.find('-')));
	line = line.substr(line.find('-') + 1, std::string::npos);
	date.month = std::stoi(line.substr(0, line.find('-')));
	line = line.substr(line.find('-') + 1, std::string::npos);
	date.day = std::stoi(line.substr(0, line.find(',')));

	std::cout << "Year: " << date.year << std::endl;
	std::cout << "Month: " << date.month << std::endl;
	std::cout << "Day: " << date.day << std::endl;
	return (date);
}

void	BitcoinExchange::_dataParser()
{
	std::ifstream	file("data.csv");
	std::string 	line;
	// int				i = 0;

	if (!file.is_open())
		throw (BitcoinExchange::InvalidDataBaseException());
	std::getline(file, line);
	while (std::getline(file, line))
	{
		double		rate = std::stod(line.substr(line.find(',') + 1, std::string::npos));
		s_date		date = createDate(line);

		this->_rateDB.insert(std::make_pair(date, rate));
	}
	std::cout << "RateDB size: " << this->_rateDB.size() << std::endl;
}


BitcoinExchange::BitcoinExchange()
{
	try
	{
		_dataParser();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
	*this = src;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &src)
{
	if (this != &src)
	{
		_rateDB = src._rateDB;
		_priceDB = src._priceDB;
	}
	return (*this);
}