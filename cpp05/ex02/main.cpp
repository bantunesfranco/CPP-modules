/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/21 11:45:20 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/24 18:05:15 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int	main(void)
{
	Bureaucrat	bob = Bureaucrat("Bob", 1);
	std::cout << bob << std::endl;
	Bureaucrat	bob2 = Bureaucrat("Bob2", 150);
	std::cout << bob2 << std::endl;


	PresidentialPardonForm	form1 = PresidentialPardonForm("Donald");
	std::cout << form1 << std::endl;
	bob2.signForm(&form1);
	bob2.executeForm(dynamic_cast<AForm&>(form1));
	bob.signForm(&form1);
	bob.executeForm(dynamic_cast<AForm&>(form1));

	std::cout << std::endl;
	{
	RobotomyRequestForm	form2 = RobotomyRequestForm("Joe");
	std::cout << form2 << std::endl;
	bob2.signForm(&form2);
	bob2.executeForm(dynamic_cast<AForm&>(form2));
	bob.signForm(&form2);
	bob.executeForm(dynamic_cast<AForm&>(form2));
	}
	std::cout << std::endl;
	{
	RobotomyRequestForm	form2 = RobotomyRequestForm("Joe");
	std::cout << form2 << std::endl;
	bob2.signForm(&form2);
	bob2.executeForm(dynamic_cast<AForm&>(form2));
	bob.signForm(&form2);
	bob.executeForm(dynamic_cast<AForm&>(form2));
	}
	std::cout << std::endl;
	
	ShrubberyCreationForm	form3 = ShrubberyCreationForm("Home");
	std::cout << form3 << std::endl;
	bob2.signForm(&form3);
	bob2.executeForm(dynamic_cast<AForm&>(form3));
	bob.signForm(&form3);
	bob.executeForm(dynamic_cast<AForm&>(form3));

	std::cout << std::endl;
	return (0);
}
