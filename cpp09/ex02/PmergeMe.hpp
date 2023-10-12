/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/03 16:11:18 by bfranco       #+#    #+#                 */
/*   Updated: 2023/10/12 15:13:31 by bfranco       ########   odam.nl         */
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

		static void				sortInputVector(std::vector<int>* container);
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

#endif
