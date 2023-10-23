/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   whatever.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/27 20:11:11 by bfranco       #+#    #+#                 */
/*   Updated: 2023/09/25 12:07:50 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void	swap(T* a, T* b)
{
	T temp = *a;
	*a = *b;
	*b = temp;
}

template <typename T>
T&	max(T& a, T& b)
{
	return (a > b ? a:b);
}

template <typename T>
const T&	max(const T& a, const T& b)
{
	return (a > b ? a:b);
}

template <typename T>
T&	min(T& a, T& b)
{
	return (a < b ? a:b);
}

template <typename T>
const T&	min(const T& a, const T& b)
{
	return (a < b ? a:b);
}

#endif
