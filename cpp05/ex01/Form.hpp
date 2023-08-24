/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/23 10:32:58 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/23 11:27:05 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		const int			_signGrade;
		const int			_executeGrade;
		bool				_isSigned;

		void		_checkLow(int grade);
		void		_checkHigh(int grade);
		
		class GradeTooHighException : public std::exception
		{
			virtual const char* what(void) const throw();
		};

		class GradeTooLowException : public std::exception
		{
			virtual const char* what(void) const throw();
		};

	public:
		Form();
		Form(std::string name, int signGrade, int executeGrade);
		Form(const Form& src);
		~Form();

		Form&		operator=(const Form& src);
		
		std::string	getName() const;
		int			getSignGrade() const;
		int			getExecuteGrade() const;
		bool		getIsSigned() const;

		void		beSigned(const Bureaucrat& src);
};

std::ostream&		operator<<(std::ostream& out, const Form& src);

#endif
