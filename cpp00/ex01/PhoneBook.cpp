/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: codespace <codespace@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/08 21:33:53 by codespace     #+#    #+#                 */
/*   Updated: 2023/06/09 16:55:23 by bfranco       ########   odam.nl         */
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
	if (i + 1 <= 8)
		this->nb_contacts = i + 1;
	else
		this->nb_contacts = 8;
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
	char	newstr[11];

	if (str.length() <= 10)
		return (str);
	str.copy(newstr, 10, 0);
	newstr[9] = '.';
	newstr[10] = '\0';
	return (std::string(newstr));
}

int	PhoneBook::get_nb_contacts()
{
	return (this->nb_contacts);
}

void	PhoneBook::simple_display()
{
	int	nb = this->get_nb_contacts();
	
	for (int i = 0; i < nb; i++)
	{
			std::cout << "|" << std::setw(10) << std::right << i;
			std::cout << "|" << std::setw(10) << std::right << str_trunc(this->contacts[i].get_first_name());
			std::cout << "|" << std::setw(10) << std::right << str_trunc(this->contacts[i].get_last_name());
			std::cout << "|" << std::setw(10) << std::right << str_trunc(this->contacts[i].get_nickname());
			std::cout << "|" << std::endl;
	}
}

void	PhoneBook::search()
{
	int			index = 0;
	std::string	input;

	this->simple_display();
	std::cout << "" << std::endl;
	while (index < 0 || index > 7)
	{
		std::cout << "Please enter an index between 0 and 7" << std::endl;
		std::getline(std::cin, input);
		index = std::stol(input);
	}
	this->display_details(index);
}
