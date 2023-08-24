/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.hpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/23 15:18:14 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/24 21:00:12 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string	_target;

	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& src);
		virtual ~PresidentialPardonForm();

		PresidentialPardonForm&	operator=(const PresidentialPardonForm& src);

		void		beExecuted(const Bureaucrat& src) const;
		std::string	getTarget() const;
};

std::ostream&		operator<<(std::ostream& out, const PresidentialPardonForm& src);

#endif
