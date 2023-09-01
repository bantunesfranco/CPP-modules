/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Ice.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/19 18:21:24 by bfranco       #+#    #+#                 */
/*   Updated: 2023/09/01 13:51:13 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice(Ice const& src);
		virtual ~Ice();
		
		Ice&	operator=(Ice const& src);
		
		AMateria*	clone() const;
};

#endif
