/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/27 18:42:47 by bfranco       #+#    #+#                 */
/*   Updated: 2023/09/03 17:51:12 by bfranco       ########   odam.nl         */
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

	delete base;
}
