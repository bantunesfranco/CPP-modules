/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/16 12:20:22 by bfranco       #+#    #+#                 */
/*   Updated: 2024/01/04 22:17:34 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	binarySearch(std::vector<int>& vec, int num, int start, int end)
{
	if (start >= end) {
		vec.insert(vec.begin() + start, num);
		return;
	}

	int mid = start + (end - start) / 2;

	if (vec[mid] == num) {
		vec.insert(vec.begin() + mid, num);
	} else if (vec[mid] > num) {
		binarySearch(vec, num, start, mid);
	} else {
		binarySearch(vec, num, mid + 1, end);
	}
}

void	checkStraggler(std::vector<int>& container, int& straggler, bool& hasStraggler)
{
	if (container.size() % 2 == 1)
	{
		straggler = container.back();
		container.pop_back();
		hasStraggler = true;
	}
}

void	insertOthers(const std::vector<int>& others, std::vector<int>& sorted)
{
	size_t								i = 1;
	int									jacob = 1;
	int									len = others.size();

	sorted.insert(sorted.begin(), *others.cbegin());
	while (i != others.size())
	{
		for (int j = jacobsthal(jacob); j > 0 && j > jacobsthal(jacob - 1); j--)
		{
			std::vector<int>::const_iterator	it = others.cbegin();
			if (j >= len)
				j = len - 1;
			std::advance(it, j);
			binarySearch(sorted, *it, 0, sorted.size());
			++i;
		}
		++jacob;
	}
}

void	sortPairs(std::vector< std::vector<int> >& pairs)
{
	std::vector< std::vector<int> >::iterator	it = pairs.begin();
	std::vector< std::vector<int> >				temp;

	temp.push_back(*it);
	it++;
	while (it != pairs.end())
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
	pairs = temp;
}

void	makePairs(const std::vector<int>& container, std::vector<int>& otherContainer, std::vector<int>& sortedContainer)
{
	std::vector<int>							temp;
	std::vector<int>::const_iterator			it = container.cbegin();
	std::vector< std::vector<int> >				pairs;
	
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
	std::vector< std::vector<int> >::iterator	it2 = pairs.begin();
	while (it2 != pairs.end())
	{
		otherContainer.push_back((*it2)[0]);
		sortedContainer.push_back((*it2)[1]);
		it2++;
	}
}
