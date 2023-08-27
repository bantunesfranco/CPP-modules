/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/27 18:42:47 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/27 19:37:46 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Classes.hpp"
#include <iostream>

int	main(void)
{
	Base* base = generate();
	Base& ref = *base;

	identify(base);
	identify(ref);

	std::cout << std::endl;

	Base* base2 = generate();
	Base& ref2 = *base2;

	identify(base2);
	identify(ref2);

	delete base;
	delete base2;
}
