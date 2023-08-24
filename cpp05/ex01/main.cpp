/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/21 11:45:20 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/23 12:50:26 by bfranco       ########   odam.nl         */
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

	Form	defaultForm;
	std::cout << defaultForm << std::endl;
	Form	form1 = Form("form1", 1, 1);
	std::cout << form1 << std::endl;
	Form	form2 = Form("form2", 0, 1);
	std::cout << form2 << std::endl;
	
	Form	form3 = Form("form3", 0, 1);
	Form	form4 = Form("form4", 151, 1);
	Form	form5 = Form("form5", 1, 0);
	Form	form6 = Form("form6", 1, 151);

	std::cout << "" << std::endl;

	bob.signForm(&form1);
	bob.signForm(&defaultForm);
	bob2.signForm(&form1);
	bob2.signForm(&defaultForm);

	std::cout << "" << std::endl;

	Form	form7 = Form(form1);
	std::cout << form7 << std::endl;
	form7 = form2;
	std::cout << form7 << std::endl;
	return (0);
}
