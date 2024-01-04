/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 13:46:05 by bfranco       #+#    #+#                 */
/*   Updated: 2024/01/04 22:36:16 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange
{
	private:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &src);
		~BitcoinExchange();

		BitcoinExchange &operator=(BitcoinExchange const &src);

	public:
		class InvalidDataBaseException : public std::exception
		{
			virtual const char *what() const throw();
		};

		class NegativeValueException : public std::exception
		{
			virtual const char *what() const throw();
		};

		class ValueTooLargeException : public std::exception
		{
			virtual const char *what() const throw();
		};

		class InvalidDateException : public std::exception
		{
			virtual const char *what() const throw();
		};

		static const std::map<std::string, double>	dataParser();
		static void	run(const char* inputFile, const std::map<std::string, double>& rateDB);
};

#endif
