/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.cpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/23 16:38:46 by bfranco       #+#    #+#                 */
/*   Updated: 2023/09/11 10:44:57 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5) , _target(target)
{
	std::cout << "PresidentialPardonForm constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) : AForm(src.getName(), src.getExecuteGrade(), 5) , _target(src._target)
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
		AForm::operator=(src);
	}
	return (*this);
}

std::string	PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

void	PresidentialPardonForm::beExecuted(const Bureaucrat& src) const
{
	if (this->getIsSigned() == false)
		throw FormNotSignedException();
	if (src.getGrade() > this->getExecuteGrade())
		throw GradeTooLowException();
	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

std::ostream&		operator<<(std::ostream& out, const PresidentialPardonForm& src)
{
	std::cout << "Target is: " << src.getTarget() << std::endl;
	out << "AForm name: " << src.getName() << std::endl;
	out << "AForm sign grade: " << src.getSignGrade() << std::endl;
	out << "AForm execute grade: " << src.getExecuteGrade() << std::endl;
	out << "AForm is signed: " << (src.getIsSigned() ? "True":"False") << std::endl;
	return (out);
}
