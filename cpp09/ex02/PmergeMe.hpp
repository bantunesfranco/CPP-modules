/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/03 16:11:18 by bfranco       #+#    #+#                 */
/*   Updated: 2023/09/14 10:21:15 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
#include <string>
#include <ctime>
#include <sstream>
#include <iostream>
#include <algorithm>

class PmergeMe
{
	private:
		PmergeMe();
		PmergeMe(const PmergeMe& src);
		~PmergeMe();

		PmergeMe&	operator=(const PmergeMe& src);
	
	public:
		static std::vector<int>	parseInput(int argc, char **argv);
		// static std::list<int>	parseInput(int argc, char **argv);
		
		template <typename T>
		static void				printOutput(T container)
		{
			typename T::iterator it = container.begin();
			while (it != container.end())
			{
				std::cout << *it;
				it++;
				if (it != container.end())
					std::cout << " ";
			}
			std::cout << std::endl;
		}

		template <typename T>
		static void				sortInput(T* container)
		{
			std::vector<T> sortVector;
			typename T::iterator it = container->begin();
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

		template <typename T>
		static void				insert_pair(std::vector<T>* container, std::vector<int> pair)
		{
			typename std::vector<T>::iterator it = container->begin();
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

		template <typename T>
		static T			crateMainArray(std::vector<T> sortVector)
		{
			std::vector<int> mainArray;
			typename std::vector<T>::iterator it = sortVector.begin();

			while(it != sortVector.end() && (*it).size() > 1)
			{
				mainArray.push_back((*it)[1]);
				it++;		
			}
			// insertOthers(&mainArray, sortVector);
			return (static_cast<T>(mainArray));
		}

		// template <typename T>
		// static void			insertOthers(T* mainArray, std::vector<T> sortVector)
		// {
		// 	end_sequence = []
		// 	jacob_index = 3;
			
		// 	while (jacobsthal(jacob_index) < array_len -1)
		// 	{
				
		// 		end_sequence.append(jacobsthal(jacob_index))
		// 		jacob_index += 1
		// 	}
		// 	return (end_sequence);
		// }

		static void				printTime(clock_t start, clock_t end, int size, std::string type);

		class NaNException : public std::exception
		{
			virtual const char* what() const throw();
		};

		class DuplicateException : public std::exception
		{
			virtual const char* what() const throw();
		};

		class ValueOutOfRangeException : public std::exception
		{
			virtual const char* what() const throw();
		};
};

int	jacobsthal(int n);

#endif
