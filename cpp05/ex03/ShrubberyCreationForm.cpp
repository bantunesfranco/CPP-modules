/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.cpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/24 16:40:54 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/24 19:28:16 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

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

std::string	ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

void	ShrubberyCreationForm::beExecuted(const Bureaucrat& src) const
{
	if (this->getIsSigned() == false)
		throw FormNotSignedException();
	if (src.getGrade() > this->getExecuteGrade())
		throw GradeTooLowException();

	std::string	filename = this->_target + "_shrubbery";
	std::ofstream file(filename.c_str());

	if (!file.is_open())
		throw std::runtime_error("File could not be opened");

	file << "                      ___ " << std::endl;
	file << "                _,-\'\"\"   \"\"\"\"`--. " << std::endl;
	file << "             ,-'          __,,-- \\ " << std::endl;
	file << "           ,'    __,--\"\"\"\"dF      ) " << std::endl;
	file << "          /   .-\"Hb_,--\"\"dF      / " << std::endl;
	file << "        ,'       _Hb ___dF\"-._,-' " << std::endl;
	file << "      ,'      _,-\"\"\"\"   \"\"--..__ " << std::endl;
	file << "     (     ,-'                  `. " << std::endl;
	file << "      `._,'     _   _             ; " << std::endl;
	file << "       ,'     ,' `-'Hb-.___..._,-' " << std::endl;
	file << "       \\    ,'\"Hb.-'HH`-.dHF\" " << std::endl;
	file << "        `--'   \"Hb  HH  dF\" " << std::endl;
	file << "                \"Hb HH dF " << std::endl;
	file << "                 \"HbHHdF " << std::endl;
	file << "                  |HHHF " << std::endl;
	file << "                  |HHH| " << std::endl;
	file << "                  |HHH| " << std::endl;
	file << "                  |HHH| " << std::endl;
	file << "                  |HHH| " << std::endl;
	file << "                  dHHHb " << std::endl;
	file << "                .dFd|bHb.               o " << std::endl;
	file << "      o       .dHFdH|HbTHb.          o / " << std::endl;
	file << "\\  Y  |  \\__,dHHFdHH|HHhoHHb.__       Y " << std::endl;
	file << "########################################## " << std::endl;

}

std::ostream&		operator<<(std::ostream& out, const ShrubberyCreationForm& src)
{
	std::cout << "Traget is: " << src.getTarget() << std::endl;
	out << "AForm name: " << src.getName() << std::endl;
	out << "AForm sign grade: " << src.getSignGrade() << std::endl;
	out << "AForm execute grade: " << src.getExecuteGrade() << std::endl;
	out << "AForm is signed: " << (src.getIsSigned() ? "True":"False") << std::endl;
	return (out);
}
