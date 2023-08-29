/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   easyfind.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/29 12:37:14 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/29 13:14:30 by bfranco       ########   odam.nl         */
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
void	easyfind(T& container, unsigned int i)
{
	try
	{
		typename T::iterator it;
		it = std::find(container.begin(), container.end(), i);
		if (it != container.end())
			std::cout << "Found " << i << " at index " << it - container.begin() << std::endl;
		else
			throw (ElementNotFoundException());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

#endif
