/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/03 15:59:48 by bfranco       #+#    #+#                 */
/*   Updated: 2023/10/12 15:12:24 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc <= 1)
	{
		std::cerr << "Please enter a list of numbers to sort." << std::endl;
		return (1);
	}

	std::clock_t start = clock();
	std::vector<int> inputVector = PmergeMe::parseInputVector(argc, argv);
	if (inputVector.size() == 1)
	{
		std::cout << "Input is sorted" << std::endl;
		return (0);
	}
	PmergeMe::sortInputVector(&inputVector);
	std::clock_t end = clock();
	
	PmergeMe::printOutput(inputVector);
	PmergeMe::printTime(start, end, inputVector.size(), std::string("vector"));
	
	// PmergeMe::printTime(start, end, inputList.size(), std::string("list"));
	// PmergeMe::printOutput(inputList);
	// std::vector<int>::iterator it = inputVector.begin();
	// while (it != inputVector.end())
	// {
	// 	if (it != inputVector.begin() && *it < *(it - 1))
	// 	{
	// 		std::cout << "Error: " << *it << " is not sorted." << std::endl;
	// 		return (1);
	// 	}
	// 	it++;
	// }
	return (0);
}
