/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/25 14:50:20 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/27 19:39:34 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include "Parsing.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: invalid number of arguments" << std::endl;
		return (1);
	}

	std::cout << "----------Input-----------" << std::endl;
	ScalarConverter::convert(argv[1]);
	std::cout << "--------------------------\n" << std::endl;

	std::cout << "----------Tests-----------" << std::endl;
	ScalarConverter::convert("nan");
	std::cout << std::endl;
	ScalarConverter::convert("nanf");
	std::cout << std::endl;
	ScalarConverter::convert("inf");
	std::cout << std::endl;
	ScalarConverter::convert("inff");
	std::cout << std::endl;
	ScalarConverter::convert("+inf");
	std::cout << std::endl;
	ScalarConverter::convert("+inff");
	std::cout << std::endl;
	ScalarConverter::convert("-inf");
	std::cout << std::endl;
	ScalarConverter::convert("-inff");
	std::cout << std::endl;
	ScalarConverter::convert("0");
	std::cout << std::endl;
	ScalarConverter::convert("0.1");
	std::cout << std::endl;
	ScalarConverter::convert("1.0f");
	std::cout << std::endl;
	ScalarConverter::convert("2.f");
	std::cout << std::endl;
	ScalarConverter::convert(".2f");
	std::cout << std::endl;
	ScalarConverter::convert("a");
	std::cout << std::endl;
	ScalarConverter::convert("42");
	std::cout << std::endl;
	ScalarConverter::convert("42.0");
	std::cout << std::endl;
	ScalarConverter::convert("-42.0f");
	std::cout << std::endl;
	ScalarConverter::convert(" ");
	std::cout << "--------------------------\n" << std::endl;
	
	return (0);
}
