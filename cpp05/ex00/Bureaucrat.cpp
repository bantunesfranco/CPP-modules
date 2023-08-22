/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/21 11:45:23 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/21 18:00:18 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat()
{
	std::cout << "Bureaucrat default constructor" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw this->GradeTooHighException();
	else if (grade > 150)
		throw this->GradeTooLowException();
	else
		this->_grade = grade;
	std::cout << "Bureaucrat constructor" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src)
{
	std::cout << "Bureaucrat copy constructor" << std::endl;
	*this = src;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& src)
{
	if (this != &src)
	{
		// this->_name = src.getName();
		this->_grade = src.getGrade();
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor" << std::endl;
}

std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void Bureaucrat::GradeTooLowException()
{
	std::cerr << "Grade too low (>150)" << std::endl;
}

void Bureaucrat::GradeTooHighException()
{
	std::cerr << "Grade too high (<1)" << std::endl;
}
