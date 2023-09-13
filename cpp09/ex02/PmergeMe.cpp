/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/03 16:11:10 by bfranco       #+#    #+#                 */
/*   Updated: 2023/09/13 17:55:45 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

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

void	PmergeMe::printTime(clock_t start, clock_t end, int size, std::string type)
{
	double time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::cout << "Time taken to sort " << size << " elements with std::" \
	<< type << ":  " << time * 1000000 << " us" << std::endl;
}
