/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.cpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/23 16:38:46 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/23 17:40:52 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(std::string& target) : Form("PresidentialPardonForm", 25, 5)
{
	std::cout << "PresidentialPardonForm constructor" << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src)
{
	std::cout << "PresidentialPardonForm copy constructor" << std::endl;
	*this = src;
}
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm&	PresidentialPardonForm::PresidentialPardonForm::operator=(const PresidentialPardonForm& src)
{
	std::cout << "PresidentialPardonForm assignment operator" << std::endl;
	if (this != &src)
	{
		Form::operator=(src);
	}
	return (*this);
}

void	PresidentialPardonForm::beExecuted(const Bureaucrat& src) const
{
	if (this->getIsSigned() == false)
		throw FormNotSignedException();
	if (src.getGrade() > this->getExecuteGrade())
		throw Form::GradeTooLowException();
	std::cout << src.getName() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}