/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/03 15:59:48 by bfranco       #+#    #+#                 */
/*   Updated: 2023/09/03 18:58:48 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>


int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cerr << "Please enter a list of numbers to sort." << std::endl;
		return (1);
	}

	std::set<int> input = PmergeMe::parseInput(argc, argv);
	PmergeMe::sortInput(&input);
	PmergeMe::printSet(input);
	return (0);
}
