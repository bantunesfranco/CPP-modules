/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/23 10:50:37 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/24 21:03:00 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <iostream>

AForm::AForm() : _name("default"), _signGrade(150), _executeGrade(150) ,_isSigned(false)
{
	std::cout << "AForm default constructor" << std::endl;
}

AForm::AForm(std::string name, int signGrade, int executeGrade) : _name(name), _signGrade(signGrade), _executeGrade(executeGrade), _isSigned(false)
{
	std::cout << "AForm constructor" << std::endl;
	this->_checkHigh(this->_signGrade);
	this->_checkLow(this->_signGrade);
	this->_checkHigh(this->_executeGrade);
	this->_checkLow(this->_executeGrade);
}

AForm::AForm(const AForm& src) : _name(src.getName()), _signGrade(src.getSignGrade()), _executeGrade(src.getExecuteGrade())
{
	std::cout << "AForm copy constructor" << std::endl;
	*this = src;
}

AForm::~AForm()
{
	std::cout << "AForm destructor" << std::endl;
}

AForm&	AForm::operator=(const AForm& src)
{
	std::cout << "AForm assignment operator" << std::endl;
	if (this != &src)
		this->_isSigned = src.getIsSigned();
	return (*this);
}

const char * AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char * AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char * AForm::FormNotSignedException::what() const throw()
{
	return ("Form was not signed");
}

void	AForm::_checkLow(int grade)
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

void	AForm::_checkHigh(int grade)
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

std::ostream&	operator<<(std::ostream& out, const AForm& src)
{
	out << "AForm name: " << src.getName() << std::endl;
	out << "AForm sign grade: " << src.getSignGrade() << std::endl;
	out << "AForm execute grade: " << src.getExecuteGrade() << std::endl;
	out << "AForm is signed: " << (src.getIsSigned() ? "True":"False") << std::endl;
	return (out);
}

std::string	AForm::getName(void) const
{
	return (this->_name);
}

int	AForm::getSignGrade(void) const
{
	return (this->_signGrade);
}

int	AForm::getExecuteGrade(void) const
{
	return (this->_executeGrade);
}

bool	AForm::getIsSigned(void) const
{
	return (this->_isSigned);
}

void	AForm::beSigned(const Bureaucrat& src)
{
	if (src.getGrade() <= this->_signGrade)
		this->_isSigned = true;
	else
		throw GradeTooLowException();
}
