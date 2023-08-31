/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MutantStack.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/29 20:08:03 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/31 11:04:49 by bfranco       ########   odam.nl         */
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
		MutantStack() : std::stack<T>() {}
		MutantStack(const MutantStack& src) : std::stack<T>(src) {}
		~MutantStack(){}

		MutantStack &operator=(const MutantStack& src)
		{
			if (this != src)
				std::stack<T>::operator=(src);
			return (*this);
		}

		typedef typename std::deque<T>::iterator iterator;
		
		iterator begin()
		{
			return (this->c.begin());
		}
		
		iterator end()
		{
			return (this->c.end());
		}
};

#endif
