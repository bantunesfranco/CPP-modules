/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 13:46:05 by bfranco       #+#    #+#                 */
/*   Updated: 2023/09/03 16:49:21 by bfranco       ########   odam.nl         */
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
			virtual const char *what() const throw()
			{ return ("Error: Invalid DataBase File"); }
		};

		class NegativeValueException : public std::exception
		{
			virtual const char *what() const throw()
			{ return ("Error: not a positive number."); }
		};

		class ValueTooLargeException : public std::exception
		{
			virtual const char *what() const throw()
			{ return ("Error: too large a number."); }
		};

		class InvalidDateException : public std::exception
		{
			virtual const char *what() const throw()
			{ 
				return ("Error: Invalid Date.");
			}
		};

		static std::map<std::string, double>	dataParser();
		static void	run(const char* inputFile, std::map<std::string, double> rateDB);
};

#endif
