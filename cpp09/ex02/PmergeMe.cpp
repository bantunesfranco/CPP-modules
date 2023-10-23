/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/03 16:11:10 by bfranco       #+#    #+#                 */
/*   Updated: 2023/10/23 14:05:35 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cmath>

const char* PmergeMe::ValueOutOfRangeException::what() const throw()
{
	return ("Error: Value out of range.");
}

const char* PmergeMe::NaNException::what() const throw()
{
	return ("Error: Input is not a number.");
}

// const char* PmergeMe::DuplicateException::what() const throw()
// {
// 	return ("Error: Duplicate value.");
// }

std::vector<int> PmergeMe::parseInputVector(int argc, char **argv)
{
	std::vector<int>	input;
	for (int i = 1; i < argc; i++)
	{
		std::stringstream	ss(argv[i]);
		unsigned long		num;
		ss >> num;
		try
		{
			if (ss.fail())
				throw PmergeMe::NaNException();
		if (num > 2147483647 || (num < 2147483647 && std::to_string(num).length() > 10))
				throw PmergeMe::ValueOutOfRangeException();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
			exit(1);
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
		std::stringstream	ss(argv[i]);
		unsigned long		num;
		ss >> num;
		try
		{
			if (ss.fail())
				throw PmergeMe::NaNException();
		if (num > 2147483647 || (num < 2147483647 && std::to_string(num).length() > 10))
				throw PmergeMe::ValueOutOfRangeException();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
			exit(1);
		}
		input.push_back(num);
	}
	return (input);
}

int	jacobsthal(int i)
{
	if (i == 0)
		return (0);
	if (i == 1)
		return (1);
	return ((std::pow(2, i) - std::pow(-1, i)) / 3);
}

void	checkStraggler(std::vector<int>* container, int *straggler, bool *hasStraggler)
{
	if (container->size() % 2 == 1)
	{
		*straggler = container->back();
		container->pop_back();
		*hasStraggler = true;
		std::cout << "straggler boiii" << std::endl;
	}
}

void	insertOthers(std::vector<int> others, std::vector<int>* sorted)
{
	std::vector<int>::iterator	it = others.begin();
	std::vector<int>::iterator	it2 = sorted->begin();
	size_t						jacob1, jacob2, temp;
	int							i = 0;
	
	sorted->insert(it2, *it);
	it++;
	jacob2 = 0;
	while (jacob2 < others.size() && it != others.end())
	{
		jacob1 = jacobsthal(i);
		temp = jacobsthal(i - 1);
		jacob2 = jacob1;
		if (jacob1 > others.size())
			jacob1 = others.size() - 2;
		while (jacob1 > temp && it != others.end())
		{
			sorted->insert(sorted->begin(), *(it + jacob1 ));
			std::cout << "inserting " << *(it + jacob1)<< std::endl;
			--jacob1;
			it++;
		}
		i++;
	}
}

void	sortPairs(std::vector< std::vector<int> >* pairs)
{
	std::vector< std::vector<int> >::iterator	it = pairs->begin();
	std::vector< std::vector<int> >				temp;

	temp.push_back(*it);
	it++;
	while (it != pairs->end())
	{
		std::vector< std::vector<int> >::iterator	it2 = temp.begin();
		while (it2 != temp.end())
		{
			if ((*it)[1] <= (*it2)[1])
			{
				temp.insert(it2, *it);
				break ;
			}
			it2++;
		}
		if (it2 == temp.end())
			temp.push_back(*it);
		it++;
	}
	*pairs = temp;
}

void	makePairs(std::vector<int>* container, std::vector<int>* otherContainer, std::vector<int>* sortedContainer)
{
	std::vector<int>							temp;
	std::vector<int>::iterator					it = container->begin();
	std::vector< std::vector<int> >				pairs;
	
	while (it != container->end())
	{
		temp.push_back(*it);
		it++;
		if (temp[0] > *it)
			temp.insert(temp.begin(), *it);
		else
			temp.push_back(*it);
		it++;
		pairs.push_back(temp);
		temp.clear();
	}
	sortPairs(&pairs);
	std::vector< std::vector<int> >::iterator	it2 = pairs.begin();
	while (it2 != pairs.end())
	{
		otherContainer->push_back((*it2)[0]);
		sortedContainer->push_back((*it2)[1]);
		it2++;
	}
}

void	PmergeMe::sortInputVector(std::vector<int>* container)
{
	int					straggler = 0;
	bool				hasStraggler = false;
	std::vector<int>	otherContainer, sortedContainer;

	checkStraggler(container, &straggler, &hasStraggler);
	makePairs(container, &otherContainer, &sortedContainer);
	std::cout << "straggler: " << straggler << std::endl;
	std::cout << "hasStraggler: " << hasStraggler << std::endl;
	if (hasStraggler == true)
		otherContainer.push_back(straggler);
	insertOthers(otherContainer, &sortedContainer);
	*container = sortedContainer;
}

void	PmergeMe::printTime(clock_t start, clock_t end, int size, std::string type)
{

	if (start == -1 || end == -1)
	{
		std::cerr << "Error: clock() failed." << std::endl;
		return ;
	}
	double time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::cout << "Time taken to sort " << size << " elements with std::" \
	<< type << ":  " << time * 1000 << " ms" << std::endl;
}
