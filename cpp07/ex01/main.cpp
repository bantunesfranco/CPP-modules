/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/27 20:02:41 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/28 12:37:20 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"
#include <iostream>

int	main(void)
{
	int	intArray[5] = {0, 1, 2, 3, 4};
	iter(intArray, 5, print);

	std::cout << std::endl;

	char	str[6] = "hello";
	iter(str, 6, print);
	
	std::cout << std::endl;

	std::string array[4] = {"This", "is", "a", "test"};
	iter(array, 4, print);
}
