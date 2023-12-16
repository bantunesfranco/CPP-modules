/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/16 12:20:22 by bfranco       #+#    #+#                 */
/*   Updated: 2023/12/16 12:26:20 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	binarySearch(std::list<int>& vec, int num, int start, int end)
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

void	checkStraggler(std::list<int>& container, int *straggler, bool *hasStraggler)
{
	if (container.size() % 2 == 1)
	{
		*straggler = container.back();
		container.pop_back();
		*hasStraggler = true;
		std::cout << "straggler boiii" << std::endl;
	}
}

void	insertOthers(const std::list<int>& others, std::list<int>& sorted)
{
	std::list<int>::const_iterator	it = others.cbegin();
	while (it != others.cend())
	{
		binarySearch(sorted, *it, 0, sorted.size());
		++it;
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

void	makePairs(const std::list<int>& container, std::list<int>& otherContainer, std::list<int>& sortedContainer)
{
	std::list<int>							temp;
	std::list<int>::const_iterator			it = container.cbegin();
	std::vector< std::list<int> >				pairs;
	
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
	std::vector< std::list<int> >::iterator	it2 = pairs.begin();
	while (it2 != pairs.end())
	{
		otherContainer.push_back((*it2)[0]);
		sortedContainer.push_back((*it2)[1]);
		it2++;
	}
}
