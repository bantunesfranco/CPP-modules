/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MutantStack.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/29 20:08:03 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/30 16:51:30 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() : std::stack<T>
		{
			return ;
		}

		MutantStack(const MutantStack& src) : std::stack<T>
		{
			*this = src;
		}

		~MutantStack()
		{
			return ;
		}

		MutantStack &operator=(const MutantStack& src) : std::stack<T>
		{
			if (this != src)
			{
				std::stack<T>::operator=(src);
			}
			return (*this);
		}

		typedef typename std::deque<T>::iterator iterator;
		
		// iterator begin()
		// {
		// 	return (std::deque<T>::begin());
		// }
		
		// iterator end()
		// {
		// 	return (std::deque<T>::end());
		// }

};

#endif
