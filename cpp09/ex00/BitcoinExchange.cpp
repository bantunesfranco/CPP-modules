/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 13:46:07 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/31 15:10:06 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>

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
		std::string	date = line.substr(0, line.find(','));
		long double		rate = std::stod(line.substr(line.find(',') + 1, std::string::npos));

		std::cout << date << std::endl;
		std::cout << rate << std::endl;
		// this->_rateDB.insert(std::pair<BitcoinExchange::s_date, double>(date, rate));
	}
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