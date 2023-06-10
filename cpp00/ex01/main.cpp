/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: codespace <codespace@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/08 21:33:55 by codespace     #+#    #+#                 */
/*   Updated: 2023/06/10 13:00:43 by codespace     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

int main(void)
{
	PhoneBook	phonebook;
	std::string	input;

	while (1)
	{
		std::cout << "Enter a command : ADD | SEARCH | EXIT" << std::endl;
		std::getline(std::cin, input);
		if (!input.compare("ADD"))
			phonebook.add();
		else if (!input.compare("SEARCH"))
			phonebook.search();
		else if (!input.compare("EXIT"))
			return (0);
	}
	return (0);
}
