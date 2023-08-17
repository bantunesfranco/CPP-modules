/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/13 09:16:28 by bruno         #+#    #+#                 */
/*   Updated: 2023/08/17 11:12:36 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main( void )
{
	{
		Fixed		a;
		Fixed const	b(Fixed(5.05f) * Fixed(2));
		
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max(a, b) << std::endl;
		std::cout << Fixed::min(a, b) << std::endl;
	}
	{
		Fixed	a(3);
		Fixed	b(10);
		
		std::cout << "" << std::endl;
		std::cout << b + a << std::endl;
		std::cout << b - a << std::endl;
		std::cout << b * a << std::endl;
		std::cout << b / a << std::endl;
		std::cout << b % a << std::endl;
	}
	{
		Fixed	a(3.25f);
		Fixed	b(10.5f);
		
		std::cout << "" << std::endl;
		std::cout << b + a << std::endl;
		std::cout << b - a << std::endl;
		std::cout << b * a << std::endl;
		std::cout << b / a << std::endl;
		std::cout << b % a << std::endl;
	}
	return (0);
}
