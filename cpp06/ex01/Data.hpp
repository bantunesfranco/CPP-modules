/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Data.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/27 17:15:26 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/27 17:56:03 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <string>
#include <iostream>

class Data
{
	private:
		std::string	_name;
		int			_balance;
		int			_accountNumber;
		int			_pinCode;
		
	public:
		Data();
		Data(const Data &copy);
		~Data();
		Data& operator=(const Data &src);

		std::string	getName() const;
		int			getBalance() const;
		int			getAccountNumber() const;
		int			getPinCode() const;
};

std::ostream&	operator<<(std::ostream &out, const Data &src);

#endif
