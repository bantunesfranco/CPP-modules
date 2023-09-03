/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/03 15:59:48 by bfranco       #+#    #+#                 */
/*   Updated: 2023/09/03 16:03:27 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include "PmergeMe.hpp"
#include <iostream>
#include <sstream>

int	main(int argc, char **argv)
{
	
	if (argc == 1)
	{
		std::cerr << "Please enter a list of numbers to sort." << std::endl;
		return (1);
	}
	for (int i = 1; i < argc; i++)
	{
		std::stringstream ss(argv[i]);
		int num;
		ss >> num;
		std::cout << num << std::endl;
	}
	return (0);
}