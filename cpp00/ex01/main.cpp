/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: codespace <codespace@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/08 21:33:55 by codespace     #+#    #+#                 */
/*   Updated: 2023/07/15 19:14:44 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

int main(void)
{
	PhoneBook	phonebook;
	std::string	input;

	while (!std::cin.eof())
	{
		std::cout << "Enter a command : ADD | SEARCH | EXIT" << std::endl;
		std::getline(std::cin, input);
		if (input == "ADD")
			phonebook.add();
		else if (input == "SEARCH")
			phonebook.search();
		else if (input == "EXIT")
			return (0);
	}
	return (0);
}
