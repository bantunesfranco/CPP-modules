/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/03 16:11:10 by bfranco       #+#    #+#                 */
/*   Updated: 2023/09/18 14:32:59 by bfranco       ########   odam.nl         */
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

int	jacobsthal(int n)
{
	if (n == 0)
		return 0;

	if (n == 1)
		return 1;

	return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

static void				insert_pair(std::vector< std::vector<int> >* container, std::vector<int> pair)
{
	std::vector< std::vector<int> >::iterator it = container->begin();
	while (it != container->end())
	{
		if (pair[1] <= (*it)[1]) {
			container->insert(it, pair);
			return ;
		}
		it++;
	}
	container->push_back(pair);
}

static void insertOthers(std::vector<int>* mainArray, std::vector< std::vector<int> > sortVector)
{
	std::vector< std::vector<int> >::iterator it2 = sortVector.begin();
	while (it2 != sortVector.end())
	{
		std::vector<int>::iterator it = std::lower_bound(mainArray->begin(), (mainArray->end()), (*it2)[0]);
		mainArray->insert(it, (*it2)[0]);
		it2++;
	}
	// int size = sortVector.size();
	// int i = 0;
	// int index = 2;
	// int prev = -1;
	// while (size - i >= 0)
	// {
	// 	int jacob = jacobsthal(index);
	// 	while (jacob > prev && i <= size)
	// 	{
	// 		if (jacob >= size)
	// 			jacob = size - 1;
	// 		std::vector<int>::iterator it = std::lower_bound(mainArray->begin(), mainArray->end(), (sortVector[jacob])[0]);
	// 		mainArray->insert(it, (sortVector[jacob])[0]);
	// 		i++;
	// 		jacob--;
	// 	}
	// 	index++;
	// 	prev = jacobsthal(index - 1);
	// }
}

static std::vector<int>			crateMainArray(std::vector< std::vector<int> > sortVector)
{
	std::vector<int> mainArray;
	std::vector< std::vector<int> >::iterator it = sortVector.begin();

	while(it != sortVector.end() && (*it).size() > 1)
	{
		mainArray.push_back((*it)[1]);
		it++;		
	}
	insertOthers(&mainArray, sortVector);
	return (mainArray);
}

void				sortInput(std::vector<int>* container)
{
	std::vector< std::vector<int> > sortVector;
	std::vector<int>::iterator it = container->begin();
	while (it != container->end())
	{
		std::vector<int> temp;

		temp.push_back(*it);
		if (it + 1 != container->end())
			temp.push_back(*(it + 1));
		if (temp[0] < temp[1])
			temp.swap(temp);
		insert_pair(&sortVector, temp);
		it += 2;
	}
	*container = crateMainArray(sortVector);
}
