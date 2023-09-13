/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/29 12:35:14 by bfranco       #+#    #+#                 */
/*   Updated: 2023/09/13 15:32:26 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <cstdlib>

int	main(void)
{
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	std::cout << std::endl;

	{
		Span sp = Span(5);

		for (int i = 0; i < 5; i++)
		{
			sp.addNumber(42);
		}
	}

	std::cout << std::endl;
	
	{
		Span sp = Span(5);
		
		try
		{
			for (int i = 0; i < 6; i++)
			{
				sp.addNumber(i*i);
			}
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	std::cout << std::endl;

	{
		Span sp = Span(10);

		try
		{
			std::cout << sp.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{		
			sp.addNumber(6);
			std::cout << sp.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	
	std::cout << std::endl;

	std::vector<int> vec;
	std::srand((unsigned)time(NULL));
	for (int i=0; i < 10000; i++)
		vec.push_back(std::rand() % 2000000);
	{
		Span sp = Span(10000);
		sp.addNumber(vec.begin(), vec.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	std::cout << std::endl;

	for (int i=0; i < 200000; i++)
		vec.push_back(std::rand() % 2000000);
	{
		Span sp = Span(300000);
		sp.addNumber(vec.begin(), vec.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	return (0);
}
