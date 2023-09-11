/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/23 10:50:37 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/23 17:37:25 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>

Form::Form() : _name("default"), _signGrade(150), _executeGrade(150) ,_isSigned(false)
{
	std::cout << "Form default constructor" << std::endl;
}

Form::Form(std::string name, int signGrade, int executeGrade) : _name(name), _signGrade(signGrade), _executeGrade(executeGrade), _isSigned(false)
{
	std::cout << "Form constructor" << std::endl;
	this->_checkHigh(this->_signGrade);
	this->_checkLow(this->_signGrade);
	this->_checkHigh(this->_executeGrade);
	this->_checkLow(this->_executeGrade);
}

Form::Form(const Form& src) : _name(src.getName()), _signGrade(src.getSignGrade()), _executeGrade(src.getExecuteGrade())
{
	std::cout << "Form copy constructor" << std::endl;
	*this = src;
}

Form&	Form::operator=(const Form& src)
{
	std::cout << "Form assignment operator" << std::endl;
	if (this != &src)
		this->_isSigned = src.getIsSigned();
	return (*this);
}

const char * Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char * Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char * Form::FormNotSignedException::what() const throw()
{
	return ("Form was not signed");
}

void	Form::_checkLow(int grade)
{
	try
	{
		if (grade > 150)
			throw GradeTooLowException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	Form::_checkHigh(int grade)
{
	try
	{
		if (grade < 1)
			throw GradeTooHighException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

std::ostream&	operator<<(std::ostream& out, const Form& src)
{
	out << "Form name: " << src.getName() << std::endl;
	out << "Form sign grade: " << src.getSignGrade() << std::endl;
	out << "Form execute grade: " << src.getExecuteGrade() << std::endl;
	out << "Form is signed: " << (src.getIsSigned() ? "True":"False") << std::endl;
	return (out);
}

Form::~Form()
{
	std::cout << "Form destructor" << std::endl;
}

std::string	Form::getName(void) const
{
	return (this->_name);
}

int	Form::getSignGrade(void) const
{
	return (this->_signGrade);
}

int	Form::getExecuteGrade(void) const
{
	return (this->_executeGrade);
}

bool	Form::getIsSigned(void) const
{
	return (this->_isSigned);
}

void	Form::beSigned(const Bureaucrat& src)
{
	if (src.getGrade() <= this->_signGrade)
		this->_isSigned = true;
	else
		throw GradeTooLowException();
}
