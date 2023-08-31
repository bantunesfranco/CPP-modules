/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 13:46:05 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/31 17:54:20 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>

class BitcoinExchange
{
	public:
		class InvalidDataBaseException : public std::exception
		{
			virtual const char *what() const throw()
			{ return ("Invalid DataBase File"); }
		};

		class InvalidRateException : public std::exception
		{
			virtual const char *what() const throw()
			{ return ("Invalid Rate Value"); }
		};

		class InvalidPriceException : public std::exception
		{
			virtual const char *what() const throw()
			{ return ("Invalid Price Value"); }
		};

		class InvalidDateException : public std::exception
		{
			virtual const char *what() const throw()
			{ return ("Invalid Date"); }
		};
		
		struct s_date
		{
			size_t	year;
			size_t	month;
			size_t	day;
		} ;

		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &src);
		~BitcoinExchange();

		BitcoinExchange &operator=(BitcoinExchange const &rhs);

		void							run();
		std::map<s_date, double>	getRateDB() const;
		std::map<s_date, double>	getPriceDB() const;

	private:
		std::map<s_date, double> _rateDB;
		std::map<s_date, double> _priceDB;

		void	_dataParser();
};

#endif
