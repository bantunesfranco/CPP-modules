/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Parsing.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/27 10:45:02 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/27 12:52:46 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Parsing.hpp"
#include <iostream>

bool	isInt(std::string input)
{
	std::cout << "isInt called" << std::endl;
	if (input.length() == 0)
		return (false);
	if (!isdigit(input[0]) && input[0] != '-' && input[0] != '+')
		return (false);
	if (input.find_first_not_of("0123456789", 1) != std::string::npos)
		return (false);
	return (true);
}
bool	isFloat(std::string input)
{
	std::cout << "isFloat called" << std::endl;
	if (input.length() == 0)
		return (false);
	if (!isdigit(input[0]) && input[0] != '-' && input[0] != '+' && input[0] != '.')
		return (false);
	if (input.find_first_of("f") != input.length() - 1)
		return (false);
	int dot = 0;
	for (int i = 0; input[i]; i++)
		if (input[i] == '.')
			dot++;
	if (dot != 1)
		return (false);
	if (input.find_first_not_of("0123456789.f", 1) != std::string::npos)
		return (false);
	return (true);
}

bool	isDouble(std::string input)
{
	std::cout << "isDouble called" << std::endl;
	if (input.length() == 0)
		return (false);
	if (!isdigit(input[0]) && input[0] != '-' && input[0] != '+' && input[0] != '.')
		return (false);
	int dot = 0;
	for (int i = 0; input[i]; i++)
		if (input[i] == '.')
			dot++;
	if (dot > 1)
		return (false);
	if (input.find_first_not_of("0123456789.", 1) != std::string::npos)
		return (false);
	return (true);
}

bool isChar(std::string input)
{
	std::cout << "isChar called" << std::endl;
	if (input.length() != 1)
		return (false);
	if (input[0] < 0 || input[0] > 128)
		return (false);
	return (true);
}

bool isPseudoLiteral(std::string input)
{
	std::cout << "isPseudoLiteral called" << std::endl;
	if (input == "nan" || input == "nanf" || input == "inf" || input == "inff" || input == "-inff")
		return (true);
	return (false);
}
