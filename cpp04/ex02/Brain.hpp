/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/12 11:34:38 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/13 20:11:40 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class	Brain
{
	private:

	public:
		std::string	_ideas[100];

		Brain();
		~Brain();
		Brain(const Brain& brain);
		
		Brain& operator=(const Brain& brain);
};

#endif