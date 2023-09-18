/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/18 07:05:48 by bfranco       #+#    #+#                 */
/*   Updated: 2023/09/18 07:10:03 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMerge.h"


static void				sortInput(std::vector<int>* container)
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


static T			crateMainArray(std::vector< std::vector<int> > sortVector)
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


static void			insertOthers(T* mainArray, std::vector<T> sortVector)
{
	jacob_index = 3;
	
	while (jacobsthal(jacob_index) < sortVector.size())
	{
		std::vector< std::vector<int> >::iterator it = sortVector.begin();
		while (it != sortVector.end() && (*it).size() > 1)
		{
			if ((*it)[0] == jacobsthal(jacob_index))
				mainArray->push_back((*it)[0]);
			it++;
		}
		jacob_index++;
	}
	return (end_sequence);
}