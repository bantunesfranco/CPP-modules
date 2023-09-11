/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/03 15:59:48 by bfranco       #+#    #+#                 */
/*   Updated: 2023/09/08 11:21:30 by bfranco       ########   odam.nl         */
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

	
	std::clock_t start = clock();
	std::vector<int> inputVector = PmergeMe::parseInput(argc, argv);
	PmergeMe::sortInput(&inputVector);
	std::clock_t end = clock();
	
	// PmergeMe::printOutput(inputVector);
	PmergeMe::printTime(start, end, inputVector.size(), std::string("vector"));
	
	start = clock();
	std::list<int> inputList(inputVector.begin(), inputVector.end());
	PmergeMe::sortInput(&inputList);
	end = clock();
	
	PmergeMe::printTime(start, end, inputList.size(), std::string("list"));
	PmergeMe::printOutput(inputList);
	return (0);
}
