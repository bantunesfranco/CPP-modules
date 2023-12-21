/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/03 15:59:48 by bfranco       #+#    #+#                 */
/*   Updated: 2023/12/21 19:20:59 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

static void	sortVector(int argc, char **argv)
{
	std::clock_t start = clock();
	std::vector<int> inputVector = PmergeMe::parseInputVector(argc, argv);
	
	if (inputVector.size() > 1)
		PmergeMe::sortInputVector(inputVector);

	std::clock_t end = clock();
	
	PmergeMe::printTime(start, end, inputVector.size(), std::string("vector"));
	// PmergeMe::printOutput(inputVector);
	
	if (!std::is_sorted(inputVector.begin(), inputVector.end()))
		std::cerr << "Error: Vector is not sorted." << std::endl;
}

static void	sortList(int argc, char **argv)
{
	std::clock_t start = clock();
	std::list<int> inputList = PmergeMe::parseInputList(argc, argv);

	if (inputList.size() > 1)
		PmergeMe::sortInputList(inputList);

	std::clock_t end = clock();
	
	PmergeMe::printTime(start, end, inputList.size(), std::string("list  "));
	// PmergeMe::printOutput(inputList);
	
	if (!std::is_sorted(inputList.begin(), inputList.end()))
		std::cerr << "Error: List is not sorted." << std::endl;
}

static void	sortDeque(int argc, char **argv)
{
	std::clock_t start = clock();
	std::deque<int> inputDeque = PmergeMe::parseInputDeque(argc, argv);

	if (inputDeque.size() > 1)
		PmergeMe::sortInputDeque(inputDeque);

	std::clock_t end = clock();
	
	PmergeMe::printTime(start, end, inputDeque.size(), std::string("deque "));
	// PmergeMe::printOutput(inputDeque);
	
	if (!std::is_sorted(inputDeque.begin(), inputDeque.end()))
		std::cerr << "Error: Deque is not sorted." << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc <= 1)
	{
		std::cerr << "Please enter a list of numbers to sort." << std::endl;
		return (1);
	}
	
	sortVector(argc, argv);
	sortList(argc, argv);
	sortDeque(argc, argv);
	
	return (0);
}
