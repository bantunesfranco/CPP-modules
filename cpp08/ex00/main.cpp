/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/29 12:35:14 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/29 13:16:41 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <array>

int	main(void)
{
	std::vector<int> vec = {1, 2 , 3, 4, 5, 6, 7, 8};
	
	easyfind(vec, 7);
	easyfind(vec, 100);

	std::cout << std::endl;

	std::array<int, 8> vec2 = {1, 2 , 3, 4, 5, 6, 7, 8};
	
	easyfind(vec2, 7);
	easyfind(vec2, 100);

	std::list<int> vec3 = {1, 2 , 3, 4, 5, 6, 7, 8};
	
	easyfind(vec3, 7);
	easyfind(vec3, 100);

	return (0);
}
