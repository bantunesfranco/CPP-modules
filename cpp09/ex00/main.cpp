/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 13:44:16 by bfranco       #+#    #+#                 */
/*   Updated: 2023/09/03 16:46:16 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./btc [inputfile]" << std::endl;
		return (1);
	}
	
	try
	{
		std::map<std::string, double>	rateDB = BitcoinExchange::dataParser();
		BitcoinExchange::run(argv[1], rateDB);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	

	return (0);
}
