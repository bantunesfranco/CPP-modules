/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/01 07:59:16 by bfranco       #+#    #+#                 */
/*   Updated: 2023/09/01 08:15:24 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./RPN \"<expression>\"" << std::endl;
		return (1);
	}

	RPN::calculate(argv[1]);
	
	return (0);
}