 /* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/23 10:32:58 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/23 13:29:04 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		const int			_signGrade;
		const int			_executeGrade;
		bool				_isSigned;

		void			_checkLow(int grade);
		void			_checkHigh(int grade);
		

	public:
		AForm();
		AForm(std::string name, int signGrade, int executeGrade);
		AForm(const AForm& src);
		virtual ~AForm();

		AForm&			operator=(const AForm& src);
		
		std::string		getName() const;
		int				getSignGrade() const;
		int				getExecuteGrade() const;
		bool			getIsSigned() const;

		void			beSigned(const Bureaucrat& src);
		virtual void	beExecuted(const Bureaucrat& src) const = 0;

		class GradeTooHighException : public std::exception
		{
			virtual const char* what(void) const throw();
		};

		class GradeTooLowException : public std::exception
		{
			virtual const char* what(void) const throw();
		};

		class FormNotSignedException : public std::exception
		{
			virtual const char* what(void) const throw();
		};
	};

std::ostream&		operator<<(std::ostream& out, const AForm& src);

#endif
