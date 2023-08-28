/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Classes.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/27 18:44:17 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/28 11:25:41 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Classes.hpp"
#include <iostream>
#include <random>

Base*	generate(void)
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist(0,100);

	int	i = dist(rng) % 3;
	switch (i)
	{
		case 0:
		{
			std::cout << "Created A object" << std::endl;
			return(new A());
		}
		case 1:
		{
			std::cout << "Created B object" << std::endl;
			return(new B());
		}
		default:
		{
			std::cout << "Created C object" << std::endl;
			return(new C());
		}
	}
	return (NULL);
}

void	identify(Base* ptr)
{
	A* a = dynamic_cast<A*>(ptr);
	B* b = dynamic_cast<B*>(ptr);
	C* c = dynamic_cast<C*>(ptr);
	if (a != NULL)
		std::cout << "Ptr is of type A" << std::endl;
	else if (b != NULL)
		std::cout << "Ptr is of type B" << std::endl;
	else if (c != NULL)
		std::cout << "Ptr is of type C" << std::endl;
	else
		std::cerr << "Not A, B or C" << std::endl;
}

void	identify(Base& ref)
{
	try
	{
		A& a = dynamic_cast<A&>(ref);
		std::cout << "Ref is of type A" << std::endl;
		(void)a;
	}
	catch (std::exception& e)
	{
		(void)e;
		try
		{
			B& b = dynamic_cast<B&>(ref);
			std::cout << "Ref is of type B" << std::endl;
			(void)b;
		}
		catch (std::exception& e)
		{
			(void)e;
			try
			{
				C& c = dynamic_cast<C&>(ref);
				std::cout << "Ref is of type C" << std::endl;
				(void)c;
			}
			catch(const std::exception& e)
			{
				std::cerr << "Not A, B or C" << std::endl;
			}
		}
	}
}
