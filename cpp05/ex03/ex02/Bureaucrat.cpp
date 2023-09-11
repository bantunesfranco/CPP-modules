/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/21 11:45:23 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/24 16:43:03 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : _name("default") , _grade(150)
{
	std::cout << "Bureaucrat default constructor" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	std::cout << "Bureaucrat constructor" << std::endl;
	this->_checkHigh(this->_grade);
	this->_checkLow(this->_grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src.getName())
{
	std::cout << "Bureaucrat copy constructor" << std::endl;
	*this = src;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& src)
{
	std::cout << "Bureaucrat assignment operator" << std::endl;
	if (this != &src)
		this->_grade = src.getGrade();
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

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high (<1)");
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low (>150)");
}

void	Bureaucrat::incrementGrade(void)
{
	this->_checkHigh(--this->_grade);
	
}

void Bureaucrat::decrementGrade(void)
{
	this->_checkLow(++this->_grade);
}

void	Bureaucrat::_checkLow(int grade)
{
	try
	{
		if (grade > 150)
			throw GradeTooLowException();
	}
	catch(const std::exception& e)
	{
		this->_grade = 150;
		std::cerr << e.what() << std::endl;
	}
}

void	Bureaucrat::_checkHigh(int grade)
{
	try
	{
		if (grade < 1)
			throw GradeTooHighException();
	}
	catch(const std::exception& e)
	{
		this->_grade = 1;
		std::cerr << e.what() << std::endl;
	}
}

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& src)
{
	out << src.getName() << ", bureaucrat grade " << src.getGrade() << std::endl;
	return (out);
}

void	Bureaucrat::signForm(AForm* form)
{
	try
	{
		form->beSigned(*this);
		std::cout << this->_name << " signed " << form->getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->_name << " cannot sign " << form->getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(const AForm& form) const
{
	try
	{
		form.beExecuted(*this);
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->_name << " cannot execute " << form.getName() << " because " << e.what() << std::endl;
	}
}
