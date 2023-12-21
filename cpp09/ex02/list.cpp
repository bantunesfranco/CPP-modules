/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/16 12:20:22 by bfranco       #+#    #+#                 */
/*   Updated: 2023/12/21 23:56:09 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iterator>

void	binarySearch(std::list<int>& lst, int num, int start, int end)
{
	std::list<int>::iterator	it = lst.begin();

	if (start >= end) {
		std::advance(it, start);
		lst.insert(it, num);
		return;
	}

	int mid = start + (end - start) / 2;

	std::advance(it, mid);
	if (*it == num) {
		lst.insert(it, num);
	} else if (*it > num) {
		binarySearch(lst, num, start, mid);
	} else {
		binarySearch(lst, num, mid + 1, end);
	}
}

void	checkStraggler(std::list<int>& container, int *straggler, bool *hasStraggler)
{
	if (container.size() % 2 == 1)
	{
		*straggler = container.back();
		container.pop_back();
		*hasStraggler = true;
	}
}

void	insertOthers(const std::list<int>& others, std::list<int>& sorted)
{
	size_t								i = 1;
	int									jacob = 1;
	int									len = others.size();

	sorted.insert(sorted.begin(), *others.cbegin());
	while (i != others.size())
	{
		for (int j = jacobsthal(jacob); j > 0 && j > jacobsthal(jacob - 1); j--)
		{
			std::list<int>::const_iterator	it = others.cbegin();
			if (j >= len)
				j = len - 1;
			std::advance(it, j);
			binarySearch(sorted, *it, 0, sorted.size());
			++i;
		}
		++jacob;
	}
}

void	sortPairs(std::vector< std::list<int> >& pairs)
{
	std::vector< std::list<int> >::iterator	it = pairs.begin();
	std::vector< std::list<int> >				temp;

	temp.push_back(*it);
	it++;
	while (it != pairs.end())
	{
		std::vector< std::list<int> >::iterator	it2 = temp.begin();
		while (it2 != temp.end())
		{
			if ((*it).back() <= (*it2).back())
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
	pairs = temp;
}

void	makePairs(const std::list<int>& container, std::list<int>& otherContainer, std::list<int>& sortedContainer)
{
	std::list<int>							temp;
	std::list<int>::const_iterator			it = container.cbegin();
	std::vector< std::list<int> >				pairs;
	
	while (it != container.cend())
	{
		temp.push_back(*it);
		it++;
		if (temp.front() > *it)
			temp.insert(temp.begin(), *it);
		else
			temp.push_back(*it);
		it++;
		pairs.push_back(temp);
		temp.clear();
	}
	sortPairs(pairs);
	std::vector< std::list<int> >::iterator	it2 = pairs.begin();
	while (it2 != pairs.end())
	{
		otherContainer.push_back((*it2).front());
		sortedContainer.push_back((*it2).back());
		it2++;
	}
}
