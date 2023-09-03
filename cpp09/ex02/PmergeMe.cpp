/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/03 16:11:10 by bfranco       #+#    #+#                 */
/*   Updated: 2023/09/03 19:25:02 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sstream>
#include <iostream>
#include <algorithm>

std::set<int> PmergeMe::parseInput(int argc, char **argv)
{
	std::set<int> input;
	for (int i = 1; i < argc; i++)
	{
		std::stringstream ss(argv[i]);
		int num;
		ss >> num;
		input.insert(num);
	}
	return (input);
}

void PmergeMe::printSet(argcstd::set<int> set)
{
	std::set<int>::iterator it = set.begin();
	while (it != set.end())
	{
		std::cout << *it;
		it++;
		if (it != set.end())
			std::cout << " ";
	}
	std::cout << std::endl;
}