/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/24 19:39:02 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/24 19:44:17 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern& src);
		~Intern();

		Intern&			operator=(const Intern& src);

		AForm*			makeForm(std::string name, std::string target);

		class InvalidFormNameException : public std::exception
		{
			virtual const char* what(void) const throw();
		};
};

#endif
