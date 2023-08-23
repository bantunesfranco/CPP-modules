/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/21 11:45:20 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/23 11:13:45 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int	main(void)
{
	Bureaucrat	bob = Bureaucrat("Bob", 1);
	std::cout << bob << std::endl;
	Bureaucrat	bob2 = Bureaucrat("Bob2", 150);
	std::cout << bob2 << std::endl;

	Bureaucrat	bob3 = Bureaucrat("Bob3", 0);
	Bureaucrat	bob4 = Bureaucrat("Bob4", 151);

	std::cout << "" << std::endl;

	std::cout << bob;
	bob.incrementGrade();
	std::cout << bob;
	bob.decrementGrade();
	std::cout << bob << std::endl;

	std::cout << bob2;
	bob2.decrementGrade();
	std::cout << bob2;
	bob2.incrementGrade();
	std::cout << bob2 << std::endl;


	Bureaucrat	bob5 = Bureaucrat(bob);
	std::cout << bob5 << std::endl;
	bob5 = bob2;
	std::cout << bob5 << std::endl;

	Bureaucrat	test;
	test = bob;
	std::cout << test << std::endl;
	return (0);
}
