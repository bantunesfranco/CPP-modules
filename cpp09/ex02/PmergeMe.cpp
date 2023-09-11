/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/03 16:11:10 by bfranco       #+#    #+#                 */
/*   Updated: 2023/09/08 11:26:35 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sstream>
#include <iostream>
#include <algorithm>

std::vector<int> PmergeMe::parseInput(int argc, char **argv)
{
	std::vector<int> input;
	for (int i = 1; i < argc; i++)
	{
		std::stringstream ss(argv[i]);
		int num;
		ss >> num;
		input.push_back(num);
	}
	return (input);
}

void PmergeMe::printOutput(std::vector<int> vec)
{
	std::vector<int>::iterator it = vec.begin();
	while (it != vec.end())
	{
		std::cout << *it;
		it++;
		if (it != vec.end())
			std::cout << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::printOutput(std::list<int> list)
{
	std::list<int>::iterator it = list.begin();
	while (it != list.end())
	{
		std::cout << *it;
		it++;
		if (it != list.end())
			std::cout << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::printTime(clock_t start, clock_t end, int size, std::string type)
{
	double time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::cout << "Time taken to sort " << size << " elements with std::" \
	<< type << ":  " << time * 1000000 << " us" << std::endl;
}

void	PmergeMe::sortInput(std::vector<int>* vec)
{
	std::vector< std::vector<int> > sortVector;
	std::vector<int>::iterator it = vec->begin();
	while (it != vec->end())
	{
		std::vector<int> temp;

		std::cout << "it: " << *it << " ";
		temp.push_back(*it);
		if (it + 1 != vec->end())
			temp.push_back(*(it + 1));
		if (temp[0] < temp[1])
			temp.swap(temp);
		sortVector.push_back(temp);
		it += 2;
	}
	
}

void	PmergeMe::sortInput(std::list<int>* list)
{
	list->sort();
}
