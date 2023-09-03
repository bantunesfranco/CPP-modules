/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/03 16:11:18 by bfranco       #+#    #+#                 */
/*   Updated: 2023/09/03 19:06:01 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <set>

class PmergeMe
{
	private:
		PmergeMe();
		PmergeMe(const PmergeMe& src);
		~PmergeMe();

		PmergeMe&	operator=(const PmergeMe& src);
	
	public:
		static std::set<int>	parseInput(int argc, char **argv);
		static void				printSet(std::set<int> set);
		static void				sortInput(std::set<int>* set);

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
