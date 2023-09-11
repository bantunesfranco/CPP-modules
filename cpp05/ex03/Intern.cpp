/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/24 19:38:58 by bfranco       #+#    #+#                 */
/*   Updated: 2023/09/11 08:30:02 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

Intern::Intern()
{
	std::cout << "Intern constructor" << std::endl;
}

Intern::Intern(const Intern& src)
{
	std::cout << "Intern copy constructor" << std::endl;
	*this = src;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

Intern&	Intern::operator=(const Intern& src)
{
	std::cout << "Intern assignment operator" << std::endl;
	(void)src;
	return (*this);
}

const char* Intern::InvalidFormNameException::what(void) const throw()
{
	return ("No such form exists");
}

AForm*	Intern::makeForm(std::string name, std::string target)
{
	std::string	formNames[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	AForm*		form = NULL;
	int			i;

	for (i = 0; i < 3; i++)
		if (name == formNames[i])
			break;
	try
	{
		switch (i)
		{
			case 0:
				form = new PresidentialPardonForm(target);
				break;
			case 1:
				form = new RobotomyRequestForm(target);
				break;
			case 2:
				form = new ShrubberyCreationForm(target);
				break;
			default:
				throw InvalidFormNameException();
				break;
		}
		std::cout << "Intern creates " << form->getName() << std::endl;
		return (form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (NULL);
	}
	return (NULL);
}
