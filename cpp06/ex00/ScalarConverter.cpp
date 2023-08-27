/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/25 13:41:35 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/27 16:27:50 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "Parsing.hpp"
#include <iostream>

ScalarConverter::ScalarConverter()
{
	std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "Destructor called" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const &src)
{
	std::cout << "Assignment operator called" << std::endl;
	(void)src;
	return (*this);
}

void	ScalarConverter::convert(std::string input)
{
	for (size_t i = 0; i < input.length(); i++)
		input[i] = std::tolower(input[i]);
	if (isInt(input))
		printInt(input);
	else if (isChar(input))
		printChar(input);
	else if (isFloat(input))
		printFloat(input);
	else if (isDouble(input))
		printDouble(input);
	else if (isPseudoLiteral(input))
		printPseudoLiteral(input);
	else
		std::cerr << "Error: \"" << input << "\" : Invalid Input" << std::endl;
}