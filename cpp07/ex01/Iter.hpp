/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Iter.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/28 11:35:10 by bfranco       #+#    #+#                 */
/*   Updated: 2023/09/25 12:09:17 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void	iter(T array[], size_t len, void (*f)(T))
{
	if (!f)
		return ;
	for (size_t i = 0; i < len; i++)
		f(array[i]);
}

template <typename T>
void	iter(const T array[], size_t len, void (*f)(T))
{
	if (!f)
		return ;
	for (size_t i = 0; i < len; i++)
		f(array[i]);
}

template <typename T>
void	print(T t)
{
	std::cout << t << std::endl;
}

#endif
