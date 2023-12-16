/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/03 16:11:10 by bfranco       #+#    #+#                 */
/*   Updated: 2023/12/16 12:23:09 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

const char* PmergeMe::ValueOutOfRangeException::what() const throw()
{
	return ("Error: Value out of range.");
}

const char* PmergeMe::NaNException::what() const throw()
{
	return ("Error: Input is not a number.");
}

std::vector<int> PmergeMe::parseInputVector(int argc, char **argv)
{
	std::vector<int>	input;
	for (int i = 1; i < argc; i++)
	{
		unsigned long		num;
		try
		{
			if (argv[i] == NULL)
				throw PmergeMe::NaNException();

			std::stringstream	ss(argv[i]);
			ss >> num;
			if (ss.fail())
				throw PmergeMe::NaNException();

			if (num > 2147483647 || (num < 2147483647 && std::to_string(num).length() > 10))
					throw PmergeMe::ValueOutOfRangeException();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
			std::exit(1);
		}
		input.push_back(num);
	}
	return (input);
}

std::list<int> PmergeMe::parseInputList(int argc, char **argv)
{
	std::list<int>	input;
	for (int i = 1; i < argc; i++)
	{
		unsigned long		num;
		try
		{
			if (argv[i] == NULL)
				throw PmergeMe::NaNException();

			std::stringstream	ss(argv[i]);
			ss >> num;
			if (ss.fail())
				throw PmergeMe::NaNException();

			if (num > 2147483647 || (num < 2147483647 && std::to_string(num).length() > 10))
					throw PmergeMe::ValueOutOfRangeException();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
			std::exit(1);
		}
		input.push_back(num);
	}
	return (input);
}

void	PmergeMe::sortInputVector(std::vector<int>& container)
{
	int					straggler = 0;
	bool				hasStraggler = false;
	std::vector<int>	otherContainer, sortedContainer;

	checkStraggler(container, &straggler, &hasStraggler);
	makePairs(container, otherContainer, sortedContainer);
	if (hasStraggler == true)
		otherContainer.push_back(straggler);
	insertOthers(otherContainer, sortedContainer);
	container = sortedContainer;
}

void	PmergeMe::printTime(clock_t start, clock_t end, size_t size, std::string type)
{
	if (start == -1 || end == -1)
	{
		std::cerr << "Error: clock() failed." << std::endl;
		return ;
	}
	double time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::cout << "\nTime taken to sort " << size << " elements with std::" \
	<< type << ":  " << time * 1000 << " ms\n" << std::endl;
}
