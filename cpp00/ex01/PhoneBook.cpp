/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: codespace <codespace@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/08 21:33:53 by codespace     #+#    #+#                 */
/*   Updated: 2023/07/15 20:29:46 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

PhoneBook::PhoneBook()
{
	this->nb_contacts = 0;
}

void	PhoneBook::add()
{
	Contact		new_contact;
	static int	i = 0;
	
	new_contact.init(i % 8);
	if (!new_contact.isValid())
	{
		std::cout << "Invalid Contact" << std::endl;
		new_contact.~Contact();
		return ;
	}
	if (i < 8)
		this->nb_contacts = i + 1;
	else
		this->nb_contacts = 8;
	this->contacts[i % 8] = new_contact;
	i++;
}

void	PhoneBook::display_details(int index)
{
	std::cout << "\nFirst Name: " << this->contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << this->contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << this->contacts[index].getNickname() << std::endl;
	std::cout << "Phone Number: " << this->contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << this->contacts[index].getSecret() << "\n" << std::endl;
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

int	PhoneBook::simple_display()
{
	int	nb = this->get_nb_contacts();
	
	if (nb == 0)
	{
		std::cout << "No contacts to display\n" << std::endl;
		return (0);
	}
	std::cout << "---------------------------------------------" << std::endl;
	for (int i = 0; i < nb; i++)
	{
		std::cout << "|" << std::setw(10) << std::right << i;
		std::cout << "|" << std::setw(10) << std::right << str_trunc(this->contacts[i].getFirstName());
		std::cout << "|" << std::setw(10) << std::right << str_trunc(this->contacts[i].getLastName());
		std::cout << "|" << std::setw(10) << std::right << str_trunc(this->contacts[i].getNickname());
		std::cout << "|" << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
	return (1);
}

void	PhoneBook::search()
{
	int			index = -1;
	std::string	input;

	if (!this->simple_display())
		return ;
	std::cout << "" << std::endl;
	while (index < 0 || index >= this->nb_contacts)
	{
		std::cout << "Please enter an index between 0 and 7" << std::endl;
		std::getline(std::cin, input, (char)std::cin.eof());
		if (std::cin.eof())
			return ;
		try {
			index = std::stoi(input);
		} catch (const std::invalid_argument& ex) {
			std::cerr << "Invalid index: " << ex.what() << std::endl;
			return ;
		} catch (const std::out_of_range& ex) {
			std::cerr << "Index Out of range: " << ex.what() << std::endl;
			return ;
		}
	}
	this->display_details(index);
}
