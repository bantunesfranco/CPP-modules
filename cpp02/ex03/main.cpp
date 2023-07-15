/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/13 09:16:28 by bruno         #+#    #+#                 */
/*   Updated: 2023/07/15 08:47:36 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main( void )
{
	Point		a(1.4f, 4.2f);
	Point		b(2.1f, 3.3f);
	Point		c(3.2f, 2.1f);
	Point		d(4.2f, 1.4f);

	bool		res = bsp(a, b, c, d);
	std::cout << "Case 1 is " << (res ? "True":"False") << std::endl;
	
	return (0);
}
