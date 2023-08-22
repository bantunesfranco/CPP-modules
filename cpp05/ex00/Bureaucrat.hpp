/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/21 11:34:24 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/21 17:47:02 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>

class Bureaucrat
{
	private:
		std::string const	_name;
		int					_grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& src);
		~Bureaucrat();

		Bureaucrat&			operator=(const Bureaucrat& src);
		
		std::string 	 	getName() const;
		int 	 			getGrade() const;

		std::exception		GradeTooHighException();
		std::exception		GradeTooLowException();
};

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& src);

#endif
