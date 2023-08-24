/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.cpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/24 16:40:54 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/24 16:56:12 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137) , _target(target)
{
	std::cout << "ShrubberyCreationForm constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : AForm(src.getName(), src.getExecuteGrade(), 5) , _target(src._target)
{
	std::cout << "ShrubberyCreationForm copy constructor" << std::endl;
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	std::cout << "ShrubberyCreationForm assignment operator" << std::endl;
	if (this != &src)
	{
		AForm::operator=(src);
	}
	return (*this);
}

void	ShrubberyCreationForm::beExecuted(const Bureaucrat& src) const
{
	if (this->getIsSigned() == false)
		throw FormNotSignedException();
	if (src.getGrade() > this->getExecuteGrade())
		throw GradeTooLowException();
	
}