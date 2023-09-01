/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/29 12:35:14 by bfranco       #+#    #+#                 */
/*   Updated: 2023/09/01 17:44:45 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <array>

int	main(void)
{
	std::vector<int> container;
	for (int i = 0; i < 10; i++)
		container.push_back(i);
	try
	{
		std::vector<int>::iterator it = easyfind(container, 7);
		std::cout << "Found " << *it << std::endl;
		easyfind(container, 100);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl;

	std::array<int, 8> container2 = {1, 2 , 3, 4, 5, 6, 7, 8};
	try
	{
		std::array<int, 8>::iterator it = easyfind(container2, 7);
		std::cout << "Found " << *it << std::endl;
		easyfind(container2, 100);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::list<int> container3;
	for (int i = 0; i < 10; i++)
		container3.push_back(i);
	try
	{
		std::list<int>::iterator it = easyfind(container3, 7);
		std::cout << "Found " << *it << std::endl;
		easyfind(container3, 100);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
