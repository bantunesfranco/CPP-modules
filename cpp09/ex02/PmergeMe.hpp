/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/03 16:11:18 by bfranco       #+#    #+#                 */
/*   Updated: 2024/01/04 22:39:43 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
#include <deque>
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
		static std::deque<int>	parseInputDeque(int argc, char **argv);

		static void				sortInputVector(std::vector<int>& container);
		static void				sortInputList(std::list<int>& container);
		static void				sortInputDeque(std::deque<int>& container);

		static void				printTime(const clock_t start, const clock_t end, const size_t size, const std::string& type);

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
void	checkStraggler(std::vector<int>& container, int &straggler, bool &hasStraggler);

void	makePairs(const std::list<int>& container, std::list<int>& otherContainer, std::list<int>& sortedContainer);
void	insertOthers(const std::list<int>& others, std::list<int>& sorted);
void	checkStraggler(std::list<int>& container, int& straggler, bool &hasStraggler);

void	makePairs(const std::deque<int>& container, std::deque<int>& otherContainer, std::deque<int>& sortedContainer);
void	insertOthers(const std::deque<int>& others, std::deque<int>& sorted);
void	checkStraggler(std::deque<int>& container, int &straggler, bool &hasStraggler);

int		jacobsthal(int i);

#endif
