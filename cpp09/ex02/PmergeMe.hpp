/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/03 16:11:18 by bfranco       #+#    #+#                 */
/*   Updated: 2023/12/16 12:24:49 by bfranco       ########   odam.nl         */
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
		static std::vector<int>	parseInputVector(int argc, char **argv);
		static std::list<int>	parseInputList(int argc, char **argv);
		static void				sortInputVector(std::vector<int>& container);
		static void				sortInputVector(std::list<int>& container);
		static void				printTime(clock_t start, clock_t end, size_t size, std::string type);

		template <typename T>
		static void				printOutput(const T& container)
		{
			typename T::const_iterator it = container.cbegin();
			while (it != container.cend())
			{
				std::cout << *it;
				++it;
				if (it != container.cend())
					std::cout << " ";
			}
			std::cout << std::endl;
		}

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

void	makePairs(const std::vector<int>& container, std::vector<int>& otherContainer, std::vector<int>& sortedContainer);
void	insertOthers(const std::vector<int>& others, std::vector<int>& sorted);
void	checkStraggler(std::vector<int>& container, int *straggler, bool *hasStraggler);

void	makePairs(const std::list<int>& container, std::list<int>& otherContainer, std::list<int>& sortedContainer);
void	insertOthers(const std::list<int>& others, std::list<int>& sorted);
void	checkStraggler(std::list<int>& container, int *straggler, bool *hasStraggler);
#endif
