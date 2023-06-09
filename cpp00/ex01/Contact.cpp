/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: codespace <codespace@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/08 21:34:03 by codespace     #+#    #+#                 */
/*   Updated: 2023/06/09 14:20:10 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

void Contact::init(int index)
{
	this->_index = index;
	
	std::cout << "Enter first name:" << std::endl;
	std::getline(std::cin, this->_first_name);
	
	std::cout << "Enter last name:" << std::endl;
	std::getline(std::cin, this->_last_name);
	
	std::cout << "Enter nickname:" << std::endl;
	std::getline(std::cin, this->_nickname);
	
	std::cout << "Enter phone number:" << std::endl;
	std::getline(std::cin, this->_phone_number);
	
	std::cout << "Enter darkest secret:" << std::endl;
	std::getline(std::cin, this->_secret);
	std::cout << "" << std::endl;
}

std::string	Contact::get_first_name()
{
	return (this->_first_name);
}

std::string	Contact::get_last_name()
{
	return (this->_last_name);
}

std::string	Contact::get_nickname()
{
	return (this->_nickname);
}

std::string	Contact::get_phone_number()
{
	return (this->_phone_number);
}

std::string	Contact::get_secret()
{
	return (this->_secret);
}
