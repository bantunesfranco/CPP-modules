/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: codespace <codespace@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/08 21:33:53 by codespace     #+#    #+#                 */
/*   Updated: 2023/06/09 14:18:50 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <iomanip>

void	PhoneBook::add()
{
	Contact 	new_contact;
	static int	i = 0;
	
	new_contact.init(i);
	this->contacts[i % 8] = new_contact;
	i++;
}

void	PhoneBook::display_details(int index)
{
	std::cout << "\nFirst Name: " << this->contacts[index].get_first_name() << std::endl;
	std::cout << "Last Name: " << this->contacts[index].get_last_name() << std::endl;
	std::cout << "Nickname: " << this->contacts[index].get_nickname() << std::endl;
	std::cout << "Phone Number: " << this->contacts[index].get_phone_number() << std::endl;
	std::cout << "Darkest Secret: " << this->contacts[index].get_secret() << "\n" << std::endl;
}

std::string	str_trunc(std::string str)
{
	char	*newstr;

	newstr = NULL;
	if (str.length() <= 10)
		return (str);
	str.copy(newstr, 9, 0);
	newstr[9] = '.';
	newstr[10] = '\0';
	return (newstr);
}

void	PhoneBook::simple_display()
{
	for (int i = 0; i < 8; i++)
	{
		if (this->contacts[i].get_first_name() != "")
		{
			std::cout << "|" << std::setw(10) << std::right << i;
			std::cout << "|" << std::setw(10) << std::right << str_trunc(this->contacts[i].get_first_name());
			std::cout << "|" << std::setw(10) << std::right << str_trunc(this->contacts[i].get_last_name());
			std::cout << "|" << std::setw(10) << std::right << str_trunc(this->contacts[i].get_nickname());
			std::cout << "|" << std::endl;
		}
	}
}

void	PhoneBook::search()
{
	int			index = -1;
	std::string	input;

	this->simple_display();
	std::cout << "" << std::endl;
	while (index < 0 || index > 7)
	{
		std::cout << "Please enter an index between 0 and 7" << std::endl;
		std::getline(std::cin, input);
		index = stoi(input);
	}
	this->display_details(index);
}
