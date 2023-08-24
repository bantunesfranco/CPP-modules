/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/21 11:45:20 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/24 21:03:29 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int	main(void)
{
	Bureaucrat	bob("Bob", 1);
	std::cout << bob << std::endl;
	Bureaucrat	bob2("Bob2", 150);
	std::cout << bob2 << std::endl;

	Intern	intern;
	AForm*	form1 = intern.makeForm("PresidentialPardonForm", "Donald");
	std::cout << *form1 << std::endl;
	bob2.signForm(form1);
	bob2.executeForm(*form1);
	bob.signForm(form1);
	bob.executeForm(*form1);

	std::cout << std::endl;
	{
		AForm*	form2 = intern.makeForm("RobotomyRequestForm", "Joe");
		std::cout << *form2 << std::endl;
		bob2.signForm(form2);
		bob2.executeForm(*form2);
		bob.signForm(form2);
		bob.executeForm(*form2);
	}
	std::cout << std::endl;
	{
		AForm*	form2 = intern.makeForm("RobotomyRequestForm", "Joe");
		std::cout << *form2 << std::endl;
		bob2.signForm(form2);
		bob2.executeForm(*form2);
		bob.signForm(form2);
		bob.executeForm(*form2);
	}
	std::cout << std::endl;
	
	AForm*	form3 = intern.makeForm("ShrubberyCreationForm", "Home");
	std::cout << *form3 << std::endl;
	bob2.signForm(form3);
	bob2.executeForm(*form3);
	bob.signForm(form3);
	bob.executeForm(*form3);

	std::cout << std::endl;
	return (0);
}
