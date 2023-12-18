/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   easyfind.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/29 12:37:14 by bfranco       #+#    #+#                 */
/*   Updated: 2023/12/18 19:21:08 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>

class ElementNotFoundException : public std::exception
{
	virtual const char* what() const throw()
	{
		return ("Element Not Found");
	}
};

template <typename T>
typename T::iterator	easyfind(T& container, int i)
{
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), i);
	if (it != container.end())
		return it;
	else
		throw (ElementNotFoundException());
	return (it);
}

#endif
