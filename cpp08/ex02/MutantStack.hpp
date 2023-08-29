/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MutantStack.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/29 20:08:03 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/29 21:07:11 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutatntStack : public std::stack
{
	public:
		MutantStack();
		MutantStack(const MutantStack& src);
		~MutantStack();

		MutantStack &operator=(const MutantStack& src);

}

#endif
