/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AMateria.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/19 16:21:26 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/19 16:26:20 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include "ICharacter.hpp"
#include <string>

class AMateria
{
	protected:
		std::string const _type;

	public:
	AMateria(std::string const & type);
	~AMateria();
	AMateria(AMateria const& src);
	
	AMateria&	operator=(AMateria const& src);
	
	std::string const&	getType() const;
	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter& target);
};

#endif