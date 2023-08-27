/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Parsing.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/27 10:45:02 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/27 16:38:37 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Parsing.hpp"
#include <iostream>

bool	isInt(std::string input)
{
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
	int c = static_cast<int>(input[0]);
	if (input.length() != 1)
		return (false);
	if (c < 0 || c > 127)
		return (false);
	return (true);
}

bool isPseudoLiteral(std::string input)
{
	if (input == "nan" || input == "nanf" || input == "inf" || input == "-inf" \
	|| input == "inff" || input == "-inff"|| input == "+inf" || input == "+inff")
		return (true);
	return (false);
}

void	printInt(std::string input)
{
	int i = std::stoi(input);

	if (isprint(i))
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
	else if (i < 0 || i > 127)
		std::cout << "char: Impossible" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void	printChar(std::string input)
{
	int c = input[0];
	if (isprint(c))
		std::cout << "char: '" << static_cast<char>(c) << "'" << std::endl;
	else if (c < 0 || c > 127)
		std::cout << "char: Impossible" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << c << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void	printFloat(std::string input)
{
	float f = std::stof(input);

	if (isprint(static_cast<int>(f)))
		std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
	else if (f < 0 || f > 127)
		std::cout << "char: Impossible" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(f) << std::endl;
	if (f - static_cast<int>(f) == 0)
	{
		std::cout << "float: " << f << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(f) << ".0" << std::endl;
	}
	else
	{
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(f) << std::endl;
	}
}

void	printDouble(std::string input)
{
	double d = std::stod(input);

	if (isprint(static_cast<int>(d)))
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
	else if (d < 0 || d > 127)
		std::cout << "char: Impossible" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(d) << std::endl;
	if (d - static_cast<int>(d) == 0)
	{
		std::cout << "float: " << static_cast<float>(d) << ".0f" << std::endl;
		std::cout << "double: " << d << ".0" << std::endl;
	}
	else
	{
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
}

void	printPseudoLiteral(std::string input)
{
	if (input == "nan" || input == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (input == "inf" || input == "inff" || input == "+inf" || input == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: inff" << std::endl;
		std::cout << "double: inf" << std::endl;
	}
	else if (input == "-inf" || input == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}
