/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 13:46:05 by bfranco       #+#    #+#                 */
/*   Updated: 2023/09/02 18:42:17 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, double> _rateDB;
		std::map<std::string, double> _priceDB;

		void	_dataParser();

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
			{ return ("Error: Invalid Price Value"); }
		};

		class InvalidInputException : public std::exception
		{
			private:
				std::string _msg;

			public:
				InvalidInputException(std::string msg) : _msg(msg) {}
				virtual const char *what(std::string msg) const throw()
				{ 
					std::string err = "Error: bad input => " + msg;
					return (err.c_str());
				}
		};

		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &src);
		~BitcoinExchange();

		BitcoinExchange &operator=(BitcoinExchange const &rhs);

		void							run();
		std::map<std::string, double>	getRateDB() const;
		std::map<std::string, double>	getPriceDB() const;
};

#endif
