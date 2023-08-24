/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.hpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/24 16:40:52 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/24 21:00:17 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string	_target;

	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& src);
		virtual ~RobotomyRequestForm();

		RobotomyRequestForm&	operator=(const RobotomyRequestForm& src);

		void	beExecuted(const Bureaucrat& src) const;
		std::string	getTarget() const;
};

std::ostream&		operator<<(std::ostream& out, const RobotomyRequestForm& src);

#endif
