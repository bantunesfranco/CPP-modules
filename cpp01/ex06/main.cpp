/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/11 17:06:25 by bfranco       #+#    #+#                 */
/*   Updated: 2023/06/15 20:04:52 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{	
		std::cerr << "Invalid number of arguments" << std::endl;
		return (1);
	}

	Harl		bob = Harl();
	bob.filter(argv[1]);
	
	return (0);
}