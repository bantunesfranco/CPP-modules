/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/21 11:45:20 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/23 14:06:42 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

int	main(void)
{
	Bureaucrat	bob = Bureaucrat("Bob", 1);
	std::cout << bob << std::endl;
	Bureaucrat	bob2 = Bureaucrat("Bob2", 150);
	std::cout << bob2 << std::endl;

	AForm	defaultAForm;
	std::cout << defaultAForm << std::endl;
	AForm	Aform1 = AForm("Aform1", 1, 1);
	std::cout << Aform1 << std::endl;
	AForm	Aform2 = AForm("Aform2", 0, 1);
	std::cout << Aform2 << std::endl;
	
	AForm	Aform3 = AForm("Aform3", 0, 1);
	AForm	Aform4 = AForm("Aform4", 151, 1);
	AForm	Aform5 = AForm("Aform5", 1, 0);
	AForm	Aform6 = AForm("Aform6", 1, 151);

	std::cout << "" << std::endl;

	bob.signForm(&Aform1);
	bob.signForm(&defaultAForm);
	bob2.signForm(&Aform1);
	bob2.signForm(&defaultAForm);

	std::cout << "" << std::endl;

	AForm	Aform7 = AForm(Aform1);
	std::cout << Aform7 << std::endl;
	Aform7 = Aform2;
	std::cout << Aform7 << std::endl;
	return (0);
}
