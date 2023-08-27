/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/27 20:02:41 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/27 20:22:50 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

int	main(void)
{
	int	a = 2;
	int	b = 3;
	swap( &a, &b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << max( a, b ) << std::endl;
	
	std::string c = "chaine1";
	std::string d = "chaine2";
	swap(c, d);std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << max( c, d ) << std::endl;

	char e = 'a';
	char f = 'b';
	swap(&e, &f);std::cout << "e = " << e << ", f = " << f << std::endl;
	std::cout << "min( e, f ) = " << min( e, f ) << std::endl;
	std::cout << "max( e, f ) = " << max( e, f ) << std::endl;
	return 0;

}