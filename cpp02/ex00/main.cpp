/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruno <bruno@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/13 09:16:28 by bruno         #+#    #+#                 */
/*   Updated: 2023/06/13 09:36:04 by bruno         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main( void )
{
	Fixed	a;
	Fixed	b(a) ;
	Fixed	c;

	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return (0);
}