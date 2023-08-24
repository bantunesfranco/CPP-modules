/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.cpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/24 16:40:49 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/24 17:07:56 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45) , _target(target)
{
	std::cout << "RobotomyRequestForm constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) : AForm(src.getName(), src.getExecuteGrade(), 5) , _target(src._target)
{
	std::cout << "RobotomyRequestForm copy constructor" << std::endl;
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
	std::cout << "RobotomyRequestForm assignment operator" << std::endl;
	if (this != &src)
	{
		AForm::operator=(src);
	}
	return (*this);
}

void	RobotomyRequestForm::beExecuted(const Bureaucrat& src) const
{
	if (this->getIsSigned() == false)
		throw FormNotSignedException();
	if (src.getGrade() > this->getExecuteGrade())
		throw GradeTooLowException();
	std::cout << "* some drilling noises *" << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << this->_target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "The robotomization has failed" << std::endl;
}
