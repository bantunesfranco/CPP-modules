/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: codespace <codespace@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/08 21:34:03 by codespace     #+#    #+#                 */
/*   Updated: 2023/07/15 20:28:45 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

bool	Contact::isWhitespaceString(const std::string& str)
{
	std::string strippedStr = str;
	strippedStr.erase(0, strippedStr.find_first_not_of(" \t\n\r\f\v"));

	return (strippedStr.empty());
}

bool	Contact::isValid()
{
	if (this->_first_name.empty() || isWhitespaceString(this->_first_name))
		return (false);
	if (this->_last_name.empty() || isWhitespaceString(this->_last_name))
		return (false);
	if (this->_nickname.empty() || isWhitespaceString(this->_nickname))
		return (false);
	if (this->_phone_number.empty() || isWhitespaceString(this->_phone_number))
		return (false);
	if (this->_secret.empty() || isWhitespaceString(this->_secret))
		return (false);	
	return (true);
}

void	Contact::init(int index)
{
	this->_index = index;
	
	std::cout << "Enter first name:" << std::endl;
	std::getline(std::cin, this->_first_name);
	if (std::cin.eof())
		return ;
	std::cout << "Enter last name:" << std::endl;
	std::getline(std::cin, this->_last_name);
	if (std::cin.eof())
		return ;
	std::cout << "Enter nickname:" << std::endl;
	std::getline(std::cin, this->_nickname);
	if (std::cin.eof())
		return ;
	std::cout << "Enter phone number:" << std::endl;
	std::getline(std::cin, this->_phone_number);
	if (std::cin.eof())
		return ;
	std::cout << "Enter darkest secret:" << std::endl;
	std::getline(std::cin, this->_secret);
	if (std::cin.eof())
		return ;
	std::cout << "" << std::endl;
}

std::string	Contact::getFirstName()
{
	return (this->_first_name);
}

std::string	Contact::getLastName()
{
	return (this->_last_name);
}

std::string	Contact::getNickname()
{
	return (this->_nickname);
}

std::string	Contact::getPhoneNumber()
{
	return (this->_phone_number);
}

std::string	Contact::getSecret()
{
	return (this->_secret);
}
