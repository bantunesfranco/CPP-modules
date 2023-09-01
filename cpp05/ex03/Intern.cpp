/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/24 19:38:58 by bfranco       #+#    #+#                 */
/*   Updated: 2023/09/01 17:37:35 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <map>

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
	std::map<std::string, int> forms;
	forms["PresidentialPardonForm"] = 0;
	forms["RobotomyRequestForm"] = 1;
	forms["ShrubberyCreationForm"] = 2;

	AForm* form = NULL;
	int type = forms.find(name)->second;
	try
	{
		switch (type)
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
