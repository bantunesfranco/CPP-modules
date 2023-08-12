/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/12 11:34:38 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/12 12:27:41 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class	Brain
{
	private:
		std::string	_ideas[100];

	public:
		Brain();
		~Brain();
		Brain(const Brain& brain);
		
		Animal& operator=(const Brain& brain);
};

#endif