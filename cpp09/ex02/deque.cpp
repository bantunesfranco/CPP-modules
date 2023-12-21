/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   deque.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/16 21:14:34 by bfranco       #+#    #+#                 */
/*   Updated: 2023/12/21 19:16:02 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	binarySearch(std::deque<int>& deq, int num, int start, int end)
{
	if (start >= end) {
		deq.insert(deq.begin() + start, num);
		return;
	}

	int mid = start + (end - start) / 2;

	if (deq[mid] == num) {
		deq.insert(deq.begin() + mid, num);
	} else if (deq[mid] > num) {
		binarySearch(deq, num, start, mid);
	} else {
		binarySearch(deq, num, mid + 1, end);
	}
}

void	checkStraggler(std::deque<int>& container, int *straggler, bool *hasStraggler)
{
	if (container.size() % 2 == 1)
	{
		*straggler = container.back();
		container.pop_back();
		*hasStraggler = true;
		std::cout << "straggler boiii" << std::endl;
	}
}

void	insertOthers(const std::deque<int>& others, std::deque<int>& sorted)
{
	std::deque<int>::const_iterator	it = others.cbegin();
	size_t							i = 0;
	int								jacob = 1;

	while (i != others.size())
	{
		for (int j = jacobsthal(jacob); j >= 0 && j >= jacobsthal(jacob - 1); j--)
		{
			std::advance(it, j);
			binarySearch(sorted, *it, 0, sorted.size());
			++i;
		}
	}
}

void	sortPairs(std::deque< std::deque<int> >& pairs)
{
	std::deque< std::deque<int> >::iterator	it = pairs.begin();
	std::deque< std::deque<int> >				temp;

	temp.push_back(*it);
	it++;
	while (it != pairs.end())
	{
		std::deque< std::deque<int> >::iterator	it2 = temp.begin();
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
	pairs = temp;
}

void	makePairs(const std::deque<int>& container, std::deque<int>& otherContainer, std::deque<int>& sortedContainer)
{
	std::deque<int>							temp;
	std::deque<int>::const_iterator			it = container.cbegin();
	std::deque< std::deque<int> >				pairs;
	
	while (it != container.cend())
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
	sortPairs(pairs);
	std::deque< std::deque<int> >::iterator	it2 = pairs.begin();
	while (it2 != pairs.end())
	{
		otherContainer.push_back((*it2)[0]);
		sortedContainer.push_back((*it2)[1]);
		it2++;
	}
}
