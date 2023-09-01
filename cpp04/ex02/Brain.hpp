/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/12 11:34:38 by bfranco       #+#    #+#                 */
/*   Updated: 2023/09/01 17:08:47 by bfranco       ########   odam.nl         */
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
		
		const std::string*	getIdeaAddress(size_t i) const;
		const std::string	getIdea(size_t i) const;
		void				setIdea(size_t i, std::string idea);
};

#endif
